//
// Created by cenicol on 6/8/19.
//

#ifndef TRASH_FILE_TFOPTIONS_HPP
#define TRASH_FILE_TFOPTIONS_HPP

#include <string>

// @class TfOptions
// Provides storage for command line options.
//
class TfOptions {

public:
    bool help;
    bool version;
    std::string desc;

    TfOptions();
};


#endif //TRASH_FILE_TFOPTIONS_HPP
