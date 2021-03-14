#ifndef _ROTOR_H
#define _ROTOR_H

#include <iostream>

namespace Enigma {
    class Rotor {
    private:
        char rotor[26];
        int notch;
        void rotate();
    public:
        Rotor(const std::string*) noexcept(false);
        char get(const char);
    };
}

#endif