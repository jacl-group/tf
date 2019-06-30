//
// Created by cenicol on 6/29/19.
//

#ifndef TRASH_FILE_SHOWTYPE_HPP
#define TRASH_FILE_SHOWTYPE_HPP

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

template <class myType>
void showType(myType v) {
    int status;
    const std::type_info &ti = typeid(v);
    char *realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);
    std::cout << ti.name() << "\t=> " << realname << "\t: " << status << '\n';
    free(realname);
}

void showTypeId(const std::type_info& ti);

class ShowType {

};


#endif //TRASH_FILE_SHOWTYPE_HPP
