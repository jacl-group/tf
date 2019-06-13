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

#include <iostream>
#include <boost/program_options.hpp>
#include "../TfTools/include/TfUtils/TfOptions.hpp"
#include "../TfUtils/include/TfUtils/BoostParser.hpp"
#include "../TfUtils/include/TfUtils/TfUtils.hpp"
#include <TfTools.hpp>

namespace po = boost::program_options;

using namespace std;


int main(int ac, char** av)
{
    // Results from Command Line Parsing
    TfOptions options;

    // Create a command line parser, and populate it.
    BoostParser parser;
    try {
        parser.parse(ac, av, options);
    } catch(const boost::program_options::unknown_option& e) {
        // Unknown Option -
        cerr << "Unknown Option: " << e.get_option_name() << endl;
    } catch(const boost::program_options::multiple_occurrences& e) {
        cerr << e.what() << endl;
    }
    if(options.help) {
        help(options);
        return 0;
    }
    if(options.version) {
        version();
        return 0;
    }

    TfTools tf;
    tf.run(options);

    return 0;
}

