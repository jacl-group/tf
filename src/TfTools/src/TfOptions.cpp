//
// Created by cenicol on 6/8/19.
//

#include <TfTools/TfOptions.hpp>

TfOptions::TfOptions() :
    help(false),
    version(false),
    forced(false),
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
    same &= forced == rhs.forced;
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
            return false;
        }
    }
    return same;
}