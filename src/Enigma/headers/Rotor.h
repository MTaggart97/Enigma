#ifndef _ROTOR_H
#define _ROTOR_H

#include <iostream>
#include <fstream>
#include "src/Enigma/headers/config.h"

namespace Enigma {
    class Rotor {
    private:
        char rotor[26];
        int notch;
        int counter;
        const std::string NOTCH = "Notch:";
        const std::string PERMUTATIONS = "Permutations:";
        void rotate();
        int char_to_int(char);
        void set_notch(std::ifstream&, int&);
        void set_rotor(std::ifstream&, char*);
    public:
        Rotor(const ROTOR_CONFIG*) noexcept(false);
        char get(const char);
    };
}

#endif