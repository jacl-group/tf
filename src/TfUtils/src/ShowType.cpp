//
// Created by cenicol on 6/29/19.
//

#include "TfUtils/ShowType.hpp"

void showTypeId(const std::type_info& ti) {
    int status;
    char *realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);
    std::cout << ti.name() << "\t=> " << realname << "\t: " << status << '\n';
    free(realname);
}
