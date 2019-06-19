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

#include "TfTools/TfOptions.hpp"
#include "TfUtils/BoostParser.hpp"

// Use unit tests .so library
//   and
// Create the unit test main()
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

// Create the test module PaserTest
#define BOOST_TEST_MODULE ParserTest

#include <boost/test/unit_test.hpp>

using namespace std;

//
// argv[0] always is the program name.
//
static char *av0 = (char *) "tf";

/**
 * setAv2 sets av array with two arguments
 * The first argument is always "tf"
 * The second argument is supplied as opt.
 *
 * @param av array to set
 * @param opt second option
 * @return the av arrray set
 */
char **setAv2(char **av, const char *opt) {
    //shared_ptr<char**> av( new char**, delSp2 );
    av[0] = av0;
    av[1] = (char *) opt;
    return av;
}

//
// Test case: TfOptions not populated by the parser.
//
BOOST_AUTO_TEST_CASE(options_test_empty) {
    TfOptions options;
    TfOptions expected;

    // Ensure the unset options are set to their defaults.
    BOOST_CHECK(options.help == false);
    BOOST_CHECK(options.version == false);
    BOOST_CHECK(options.forced == false);
    BOOST_CHECK(options.always == false);
    BOOST_CHECK(options.once == false);
    BOOST_CHECK(options.interactive == false);
    BOOST_CHECK(options.preserve == false);
    BOOST_CHECK(options.recursive == false);
    BOOST_CHECK(options.verbose == false);
    BOOST_CHECK(options.empty == false);
    BOOST_CHECK(options.restore == false);
    BOOST_CHECK(options.undo == false);
    BOOST_CHECK(options.files.empty());
    BOOST_CHECK(options.desc.empty());

    BOOST_CHECK(options == expected);
}

//
// Test case: tf --help
//
BOOST_AUTO_TEST_CASE(options_test_help) {
    TfOptions options;
    TfOptions expected;

    // Build the command line.
    int ac = 2;
    char *av[2];
    setAv2(av, "--help");

    // Parse the command line.
    BoostParser parser;
    parser.parse(ac, setAv2(av, "--help"), options);

    // Get the description from the parser.
    string desc{parser.getDesc()};

    // Check the options.
    expected.help = true;
    BOOST_CHECK(options.help == true);
    BOOST_CHECK(options.version == false);
    BOOST_CHECK(options.desc == parser.getDesc());
    BOOST_CHECK(options == expected);
}

//
// Test case: tf --force
//
BOOST_AUTO_TEST_CASE(options_test_version) {
    TfOptions options;
    TfOptions expected;

    // Build the command line.
    char *av[2];
    setAv2(av, "--forced");

    // Parse the command line.
    BoostParser parser;
    parser.parse(2, av, options);

    // Set test option
    expected.forced = true;

    // Verify expected
    BOOST_CHECK(options == expected);
}

