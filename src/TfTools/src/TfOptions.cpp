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

#include <TfTools/TfOptions.hpp>

#include <iostream>

using std::endl;

TfOptions::TfOptions() :
    help(false),
    version(false),
    force(false),
    always(false),
    once(false),
    interactive(false),
    preserve(false),
    recursive(false),
    verbose(false),
    empty(false),
    restore(false),
    undo(false),
    desc()
{

}

bool TfOptions::operator==(const TfOptions& rhs) {
    bool same = true;
    same &= help == rhs.help;
    same &= version == rhs.version;
    same &= force == rhs.force;
    same &= always == rhs.always;
    same &= once == rhs.once;
    same &= interactive == rhs.interactive;
    same &= preserve == rhs.preserve;
    same &= recursive == rhs.recursive;
    same &= verbose == rhs.verbose;
    same &= empty == rhs.empty;
    same &= restore == rhs.restore;
    same &= undo == rhs.undo;
    same &= desc == rhs.desc;
    for (auto i = 0; i < files.size(); ++i) {
        if (files[i] != rhs.files[i]) {
            std::cout << "\t" << files[i] << " != " << rhs.files[i] << "\n";
            return false;
        } else {
            std::cout << "\t" << files[i] << " == " << rhs.files[i] << "\n";

        }
    }
    return same;
}

std::ostream& operator<<(std::ostream& os, const TfOptions &rhs) {
    os << "help: \t\t"  << rhs.help    << endl;
    os << "version: \t" << rhs.version << endl;
    os << "... not fully implemented" << endl;
    if(rhs.files.size()) {
        os << "files:" << endl;
        for(auto f : rhs.files) {
            os << "\t" << f << endl;
        }
    }

    return os;
}