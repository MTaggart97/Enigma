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

char Rotor::encrypt(const char c, const bool to_rotate) {
    if (to_rotate) rotate();
    // Ensure index is > 0 and < 26
    int index = (26 + (Enigma::Utils::char_to_int(c) + counter) % 26) % 26;
    char ch = rotor[index];
    return ch;
}

void Rotor::rotate() {
    ++counter;
}

bool Rotor::on_notch() {
    // Using mod on the off chance that the counter is not zeroed
    if (counter % notch == 0) {
        counter = 0;
        return true;
    }
    return false;
}

int Rotor::get_index(char c) {
    int pos = 0;
    for (const char curr_c: rotor) {
        if (c == curr_c) {
            break;
        }
        pos++;
    }
    pos = (26 + (pos + counter) % 26) % 26;
    return pos;
}

char Rotor::get(int pos) {
    return rotor[(26 + (pos - counter) % 26) % 26];
}
