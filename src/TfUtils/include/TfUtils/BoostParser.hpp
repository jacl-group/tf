//
// Created by cenicol on 6/8/19.
//
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
