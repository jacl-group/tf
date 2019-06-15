//
// Created by cenicol on 6/9/19.
//

#include <iostream>

#include "TfTools/TfOptions.hpp"
#include "TfUtils/BoostParser.hpp"

// Use unit tests .so library
// and
// Create the unit test main()
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

// Create the test module PaserTest
#define BOOST_TEST_MODULE ParserTest
#include <boost/test/unit_test.hpp>

using namespace std;

//
// Test case: TfOptions not populated by the parser.
//
BOOST_AUTO_TEST_CASE( options_test_empty )
{
    TfOptions options;

    // Ensure the unset options are set to their defaults.
    BOOST_CHECK(options.help == false);
    BOOST_CHECK(options.version == false);
    BOOST_CHECK(options.desc.empty());
}

//
// Test case: tf --help
//
BOOST_AUTO_TEST_CASE( options_test_help )
{
    TfOptions options;

    // Build the command line.
    int ac = 2;
    char * av0 = (char*) "tf";
    char * av1 = (char*) "--help";
    char * av[2] {av0, av1};

    // Parse the command line.
    BoostParser parser;
    parser.parse(ac, av, options);

    // Get the description from the parser.
    string desc { parser.getDesc() };

    // Check the options.
    BOOST_CHECK(options.help == true);
    BOOST_CHECK(options.version == false);
    BOOST_CHECK(options.desc == parser.getDesc());
}

char** setAv2(char** av, const char * opt)
{
    static char * av0 = (char*) "tf";
    av[0] = av0;
    av[1] = (char*) opt;
    return av;
}

//
// Test case: tf --verbose
//
BOOST_AUTO_TEST_CASE( options_test_version )
{
    TfOptions options;

    // Build the command line.
    int ac = 2;
    char * av[2];
    setAv2(av, "--version");

    // Parse the command line.
    BoostParser parser;
    parser.parse(ac, av, options);

    // Get the description from the parser.
    string desc { parser.getDesc() };

    // Check the options.
    BOOST_CHECK(options.help == false);
    BOOST_CHECK(options.version == true);
    BOOST_CHECK(options.desc == parser.getDesc());
}

//
// Test unknown short option
//
