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
#include "TfTools/TfOptions.hpp"
#include <TfTools/TfTools.hpp>
#include "TfUtils/BoostParser.hpp"
#include "TfUtils/TfUtils.hpp"

namespace po = boost::program_options;

using namespace std;

int main(int ac, char** av)
{
    // Results from Command Line Parsing
    // Use by the command line parser to send options to be executed.
    TfOptions options;

    // Create an array containing av
    vector<string> argv(ac);
    copy(av, (av+ac), argv.begin());

    // Create a command line parser, and populate it.
    int result;
    BoostParser parser;
    try {
        parser.parse(ac, av, options);
    } catch(const boost::program_options::unknown_option& e) {
        // Unknown Option found
        cerr << "Unknown Option: " << e.get_option_name() << endl;
    } catch(const boost::program_options::multiple_occurrences& e) {
        // Option repeated
        cerr << e.what() << endl;
    } catch(...) {
        cerr << "Unexpected Exception" << endl;
    }

    // Do Help and exit
    if(options.help) {
        help(options);
        return 0;
    }

    // Do version and exit
    if(options.version) {
        version();
        return 0;
    }

    // Run command
    return TfTools().run(options);
}

