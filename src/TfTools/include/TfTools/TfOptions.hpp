//
// Created by cenicol on 6/8/19.
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
