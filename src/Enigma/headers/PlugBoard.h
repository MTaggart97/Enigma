#ifndef _PLUGBOARD_H
#define _PLUGBOARD_H

#include <iostream>

namespace Enigma {
    class PlugBoard {
    private:
        char plugboard[26];
        char int_to_char(int);
        int char_to_int(char);
        void read_file(const std::string, char*);
    public:
        PlugBoard(const std::string);
        char get(const char);
        void put(const char);
    };
}

#endif