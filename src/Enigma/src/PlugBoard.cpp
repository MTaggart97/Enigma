#include "PlugBoard.hpp"
#include "utils.hpp"
#include "config.hpp"
#include <stdlib.h>

using Enigma::PlugBoard;

Enigma::PlugBoard::PlugBoard(const PLUGBOARD_CONFIG* p_config) noexcept(false) {
    // Copy each element into array (as data is in a struct)
    length = 0;
    for (int i = 0; i < 13; i++) {
        if (!*p_config->wiring[i]) {
            break;
        }
        for (int j = 0; j < 13; j++) {
            plugboard[i][0] = p_config->wiring[i][0];
            plugboard[i][1] = p_config->wiring[i][1];
        }
        length++;
    }
}

char Enigma::PlugBoard::get(const char x) {
    for (size_t i = 0; i < length; i++) {
        if (plugboard[i][0] == x) {
            return plugboard[i][1];
        } else if (plugboard[i][1] == x) {
            return plugboard[i][0];
        }
    }
    int pos = Enigma::Utils::char_to_int(x);
    return (pos < 26 && pos > 0) ? x : ' ';
}
