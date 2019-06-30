//
// Created by cenicol on 6/8/19.
//

#include "include/TfUtils/BoostParser.hpp"

#include <iostream>
#include <vector>

#include <TfUtils/ShowType.hpp>

#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>

namespace po = boost::program_options;

using namespace std;

/// options_description for all BoostParser instances.
boost::program_options::options_description BoostParser::desc_("Allowed options");

/// ctor
BoostParser::BoostParser() {
    // The (options_description) desc class is a static instance.
    // It needs to be set only once for all instances of BoostParser.
    // I check to see if the container is empty() to determine if it needs to be set.
    if (desc_.options().empty()) {
        // Declare the supported options.
        desc_.add_options()
                ("force,f", "ignore nonexistent files, never prompt")
                (",i", "prompt before every removal")
                (",I",
                 "prompt once before removing more than three files, or when removing recursively; less intrusive than -i while still giving protection against most mistakes")
                ("interactive",
                 "prompt according to WHEN: never, once (-I), or always (-i); without WHEN, prompt always")
                ("one-file-system",
                 "when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument")
                ("no-preserve-root", "do not treat '/' specially")
                ("preserve-root", "do not remove '/' (default)")
                ("recursive,rR", "remove directories and their contents recursively")
                (",R", "remove directories and their contents recursively")
                ("dir,d", "remove empty directories")
                ("help", "produce help message")
                ("version", "output version information and exit")
                //("path", po::value< vector<string> >(), "path of file to process")
                ;
    }

}

/// getDesc() is a convienance method which provides the description string output from
/// options_description.
///
/// \return The description string generated from the static options_description desc_.
string BoostParser::getDesc() const {
    ostringstream oss;
    oss << desc_;
    return oss.str();
}

/// parse() parse the command line from main() and stores the results into options.
///
/// \param ac argc from main
/// \param av arv from main
/// \param options TfOptions instance to fill after parsing the command line
void BoostParser::parse(int ac, char **av, TfOptions &options) {
#if 1
    cout << "Arguments from main()" << endl;
    cout << "\tac: " << ac << endl;
    for (char **p = av; p < (av + ac); ++p) {
        cout << "\t" << *p << endl;
    }
#endif

    // Set options description
    options.desc = getDesc();

    // Hidden options, will be allowed on the command line, but not shown to the user.
    po::options_description hidden("Hidden Options");
    hidden.add_options()
            ("path", po::value< vector<string> >(), "path of file to process")
            ;

    // Build the command line parser.
    po::options_description cmdline_options;
    cmdline_options.add(BoostParser::desc_).add(hidden);

    // Positional Options
    po::positional_options_description p;
    p.add("path", -1);

    // Variable Map
    po::variables_map vm;

    // Load the variable map
    po::store(po::command_line_parser(ac,av).options(cmdline_options).positional(p).run(), vm);
    po::notify(vm);

    const bool verbose {true};
#if 1
    BOOST_LOG_TRIVIAL(trace) << "Results from parse" << endl;
#endif

    if (vm.count("help")) {
        options.help = true;
    }

    if (vm.count("version")) {
        options.version = true;
    }

    if (vm.count("force")) {
        cout << "force: " << vm.count("force") << endl;
        options.force = true;
    }

    if (vm.count("-i")) {
        cout << "always: " << vm.count("-i") << endl;
        options.always = true;
    }

    if (vm.count("-I")) {
        cout << "once: " << vm.count("-I") << endl;
        options.once = true;
    }

    cout << "vm.count(\"path\"): " << vm.count("path") << endl;
    if (vm.count(("path"))) {

        int len = vm["path"].as< vector<string> >().size();
        cout << "\tsize: " << len << endl;
        const vector<string> &rvec = vm["path"].as< vector<string> >();
        ostream_iterator<string> oit(std::cout, " ");
        cout << "\t";
        copy(rvec.cbegin(), rvec.cend(), oit);
        cout << endl;

        options.files = vm["path"].as< vector<string> >();
#if 0
        for (auto path : vm["path"].as< vector<string> >()) {
            cout << "\t" << path << endl;
        }
#endif
    }


    cout << "Vector of Options" << endl;
    cout << "vm.size(): " << vm.size() << endl;
    for (auto item : vm) {
        cout << "\t" << item.first;
        try {
            const type_info &ti = item.second.value().type();
#if 0
            //showType(item.second.value());
            showTypeId(ti);
#endif
            if( typeid(string) == ti) {
                string value = boost::any_cast<string>(item.second.value());
                cout << ": " << (value.empty() ? "empty" : value) << endl;
            } else {
                cout << ": unknown-type" << endl;
            }
        } catch (const boost::bad_any_cast &e) {
            cout << endl;
            cerr << e.what() << endl;
        } catch (exception e) {
            cout << endl;
            cerr << e.what() << endl;
        }
    }
}
