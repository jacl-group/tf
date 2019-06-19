//
//    This file is part of tf.
//
//    tf is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    tf is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with tf.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef TRASH_FILE_TFOPTIONS_HPP
#define TRASH_FILE_TFOPTIONS_HPP

#include <string>
#include <vector>

// @class TfOptions
// Provides storage for command line options.
//
class TfOptions {

public:
    bool help;              // --help
    bool version;           // --version
    bool forced;            // --forced, -f
    bool always;            // -i
    bool once;              // -I
    bool interactive;       // --interactive[=WHEN]
                            //      once (-I)
                            //      always
                            //      never
    bool preserve;          // preserve-root
    bool recursive;         // --recursive, -R, -r
    bool verbose;           // --verbose, -v
    bool empty;             // --trash-empty, -e
    bool restore;           // --trash-restore FILES...
    bool undo;              // --trash-undo
    std::string desc;       //
    std::vector<std::string> files; // list of files (using glob)


    TfOptions();
    bool operator==(const TfOptions & rhs);
};


#endif //TRASH_FILE_TFOPTIONS_HPP
