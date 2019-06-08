
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

void version();

int main(int ac, char** av)
{
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("force,f", "ignore nonexistent files, never prompt")
    ("i", "prompt before every removal")
    ("I", "prompt once before removing more than three files, or when removing recursively; less intrusive than -i while still giving protection against most mistakes")
    ("interactive", "prompt according to WHEN: never, once (-I), or always (-i); without WHEN, prompt always")
    ("one-file-system", "when removing a hierarchy recursively, skip any directory that is on a file system different from that of the corresponding command line argument")
    ("no-preserve-root", "do not treat '/' specially")
    ("preserve-root", "do not remove '/' (default)")
    ("recursive,rR", "remove directories and their contents recursively")
    ("dir,d", "remove empty directories")
    ("version", "output version information and exit")


    ("compression", po::value<int>(), "set compression level")
    ;

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("compression")) {
    cout << "Compression level was set to " 
	 << vm["compression"].as<int>() << ".\n";
  } else {
    cout << "Compression level was not set.\n";
  }

  return 0;
}

void version()
{
  string version {"1.0"};
  string notice =
R"END(
Copyright (C) 2019 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Written by Alexandria Pettit and Cassie E Nicol.
)END;

  cout << "tf " << version << notice;
}
