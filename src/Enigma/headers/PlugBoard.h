#ifndef _PLUGBOARD_H
#define _PLUGBOARD_H

#include <iostream>

namespace Enigma {
    class PlugBoard {
    public:
        PlugBoard(const std::string);
        char get(const char);
    };
}

#endif