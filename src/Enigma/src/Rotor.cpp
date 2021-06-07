#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"
#include "src/Enigma/headers/utils.h"
#include <fstream>

using Enigma::Rotor;

Rotor::Rotor(const ROTOR_CONFIG* r_config) {
    for (int i = 0; i < 26; i++) {
        rotor[i] = r_config->wiring[i];
    }
    notch = Enigma::Utils::char_to_int(r_config->notch);
    counter = r_config->offset;
}

char Rotor::get(const char c, const bool to_rotate) {
    // Ensure index is > 0 and < 26
    int index = (26 + (Enigma::Utils::char_to_int(c) - counter) % 26) % 26;
    char ch = rotor[index];
    if (to_rotate) rotate();
    return ch;
}

void Rotor::rotate() {
    ++counter;
}
