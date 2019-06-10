
#include <iostream>
#include <boost/program_options.hpp>
#include <TfOptions.hpp>
#include <BoostParser.hpp>
#include <TfUtils.hpp>

namespace po = boost::program_options;

using namespace std;


int main(int ac, char** av)
{
    // Results from Command Line Parsing
    TfOptions options;

    try {
        parseCommandLine(ac, av, options);
    } catch(const boost::program_options::unknown_option& e) {
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
    return 0;
}

