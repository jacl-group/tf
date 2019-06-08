
#include <iostream>
#include <boost/program_options.hpp>
#include <include/TfOptions.hpp>

namespace po = boost::program_options;

using namespace std;

void parseCommandLine(int ac, char** av, TfOptions& options);
void help(const po::options_description& desc);
void version();


int main(int ac, char** av)
{
    // Results from Command Line Parsing
    TfOptions options;

    try {
        parseCommandLine(ac, av, options);
    } catch(const boost::program_options::unknown_option& e) {
        cerr << "Unknown Option: " << e.get_option_name() << endl;
    } catch(const boost::program_options::multiple_occurrences& e) {
        cerr << e.what() << endl;
    }
    if(options.help) {
        help(options.desc);
        return 0;
    }
    if(options.version) {
        version();
        return 0;
    }
    return 0;
}

void parseCommandLine(int ac, char** av, TfOptions& options) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("force,f", "ignore nonexistent files, never prompt")
            ("i", "prompt before every removal")
            ("I",
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

    cout << "size of files: " << vm.count("files") << endl;


}

void help(const po::options_description &desc) {
    string example {
        R"END(
By default, rm does not remove directories.  Use the --recursive (-r or -R)
option to remove each listed directory, too, along with all of its contents.

To remove a file whose name starts with a '-', for example '-foo',
use one of these commands:
  rm -- -foo

  rm ./-foo

Note that if you use rm to remove a file, it might be possible to recover
some of its contents, given sufficient expertise and/or time.  For greater
assurance that the contents are truly unrecoverable, consider using shred.

)END"
    };
    cout << "Usage: tf [OPTION]... [FILE]...\n"
         << "Move the FILE(s) to the trash.\n\n";
    cout << desc << "\n";
    //cout << example;
}

void version() {
    string version{"1.0"};
    string notice{
            R"END(
Copyright (C) 2019 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Alexandria Pettit and Cassie E Nicol.
)END"};

    cout << "tf " << version << notice;
}
