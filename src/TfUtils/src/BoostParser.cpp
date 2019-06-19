//
// Created by cenicol on 6/8/19.
//

#include "include/TfUtils/BoostParser.hpp"

#include <iostream>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

boost::program_options::options_description BoostParser::desc_("Allowed options");

//
BoostParser::BoostParser()
{
    // The (options_description) desc class is a static instance.
    // It needs to be set only once for all instances of BoostParser.
    // I check to see if the container is empty() to determine if it needs to be set.
    if(desc_.options().empty()) {
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
                ("dir,d", "remove empty directories")
                ("help", "produce help message")
                ("version", "output version information and exit");
    }

}

// getDesc() is a convienance method which provides the description string output from
// options_description.
string BoostParser::getDesc() const
{
    ostringstream oss;
    oss << desc_;
    return oss.str();
}

// parse() parsed the command line from main() and stores the results into options.
//
void BoostParser::parse(int ac, char** av, TfOptions& options) {
#if 0
    cout << "ac: " << ac << endl;
    for(char** p=av; p < (av+ac); ++p) {
        cout << "\t" << *p << endl;
    }
#endif

    // Hidden options, will be allowed on the command line, but not shown to the user.
    po::options_description hidden("Hidden Options");
    hidden.add_options()
            ("file", po::value<vector<string> >(), "file")
            ;

    po::options_description cmdline_options;
    cmdline_options.add(BoostParser::desc_).add(hidden);

    options.desc = getDesc();

    // Variable Map
    po::variables_map vm;

    // Load the variable map
    po::store(po::parse_command_line(ac, av, cmdline_options), vm);
    po::notify(vm);

    if (vm.count("help")) {
        options.help = true;
    }

    if (vm.count("version")) {
        options.version = true;
    }

    if(vm.count("force")) {
        cout << "force: " << vm.count("force") << endl;
    }
}
