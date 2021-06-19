#include "Rotor.hpp"
#include "config.hpp"
#include "utils.hpp"

using Enigma::Rotor;

const char alphabet[] = ALPHABET;
bool blocked = false;

Rotor::Rotor(const ROTOR_CONFIG* r_config) {
    for (int i = 0; i < 26; i++) {
        rotor[i] = r_config->wiring[i];
    }
    notch = Enigma::Utils::char_to_int(r_config->notch) + 1;
    counter = r_config->offset;
}

char Rotor::encrypt(const char c) {
    // Ensure index is > 0 and < 26
    int index = (26 + (Enigma::Utils::char_to_int(c) + counter) % 26) % 26;
    return rotor[index];
}

void Rotor::rotate(const bool flag) {
    if (flag || (counter == notch-1)) {
        counter = (counter+1) % 26;
        blocked = false;
    } else {
        blocked = true;
    }
}

bool Rotor::on_notch() {
    return !blocked && counter == notch;
}

int Rotor::get_index(char c) {
    int pos = 0;
    for (const char curr_c: alphabet) {
        if (c == curr_c) {
            break;
        }
        pos++;
    }
    pos = (26 + (pos - counter) % 26) % 26;
    return pos;
}

char Rotor::reverse(char c) {
    char actual_char = 97 + ((26 + (Enigma::Utils::char_to_int(c) + counter) % 26) % 26);
    int pos = 0;
    for (const char curr: rotor) {
        if (curr == actual_char) {
            break;
        }
        pos++;
    }
    return Enigma::Utils::int_to_char(get_index(97 + pos));
}
