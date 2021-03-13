#include "src/Enigma/headers/PlugBoard.h"
#include <iostream>

using std::cout;
using std::endl;

Enigma::PlugBoard::PlugBoard(const std::string file) {
    cout << file << endl;
}

char Enigma::PlugBoard::get(const char x) {
    return x;
}
