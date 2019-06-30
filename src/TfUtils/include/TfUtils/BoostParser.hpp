//
// Created by cenicol on 6/8/19.
//

#ifndef TRASH_FILE_BOOSTPARSER_HPP
#define TRASH_FILE_BOOSTPARSER_HPP

#include <vector>
#include <TfTools/TfOptions.hpp>

namespace boost {
    namespace program_options {
        class options_description;
    }
}

class BoostParser
{
public:
    BoostParser();
    BoostParser(const BoostParser&) = delete;
    BoostParser& operator=(const BoostParser&) = delete;

    void parse(int ac, char**av, TfOptions& options);

    std::string getDesc() const;

protected:
    static boost::program_options::options_description desc_;
};

#endif //TRASH_FILE_BOOSTPARSER_HPP
