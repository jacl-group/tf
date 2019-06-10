//
// Created by cenicol on 6/8/19.
//

#include "BoostParser.hpp"

#include <iostream>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

void parseCommandLine(int ac, char** av, TfOptions& options) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("force,f", "ignore nonexistent files, never prompt")
            (",i", "prompt before every removal")
            (",I",
             "prompt once before removing more than three files, or when removing recursively; less intrusive than -i while still giving protection against most mistakes")
            ("interactive", "prompt according to WHEN: never, once (-I), or always (-i); without WHEN, prompt always")
            ("one-file-system",
             "when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument")
            ("no-preserve-root", "do not treat '/' specially")
            ("preserve-root", "do not remove '/' (default)")
            ("recursive,rR", "remove directories and their contents recursively")
            ("dir,d", "remove empty directories")
            ("help", "produce help message")
            ("version", "output version information and exit");

    // Hidden options, will be allowed on the command line, but not shown to the user.
    po::options_description hidden("Hidden Options");
    hidden.add_options()
            ("file", po::value<vector<string> >(), "file")
            ;

    po::options_description cmdline_options;
    cmdline_options.add(desc).add(hidden);

    ostringstream oss;
    oss << cmdline_options;
    options.desc = oss.str();

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

