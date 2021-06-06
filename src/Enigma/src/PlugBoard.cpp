#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/headers/config.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using Enigma::PlugBoard;

char int_to_char(int x);

Enigma::PlugBoard::PlugBoard(const PLUGBOARD_CONFIG* p_config) noexcept(false) {
    // Copy each element into array (as data is in a struct)
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            plugboard[i][0] = p_config->wiring[i][0];
            plugboard[i][1] = p_config->wiring[i][1];
        }
    }
}

char Enigma::PlugBoard::get(const char x) {
    for (int i = 0; i < 13; i++) {
        if (plugboard[i][0] == x) {
            return plugboard[i][1];
        } else if (plugboard[i][1] == x) {
            return plugboard[i][0];
        }
    }
    return ' ';
}
