#ifndef _ROTOR_H
#define _ROTOR_H

#include <iostream>
#include <fstream>

namespace Enigma {
    class Rotor {
    private:
        char rotor[26];
        int notch;
        int counter;
        const std::string NOTCH = "Notch:";
        const std::string PERMUTATIONS = "Permutations:";
        void rotate();
        void read_file(const std::string*, char*, int&);
        int char_to_int(char);
        void set_notch(std::ifstream&, int&);
        void set_rotor(std::ifstream&, char*);
    public:
        Rotor(const std::string*) noexcept(false);
        char get(const char);
    };
}

#endif