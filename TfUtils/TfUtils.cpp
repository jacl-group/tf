//
// Created by cenicol on 6/8/19.
//

#include "TfUtils.hpp"

#include <iostream>
#include <string>

using namespace std;

void help(const TfOptions& options) {
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
         << "Move the FILE(s) to the trash.\n";
    cout << options.desc << "\n";
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
