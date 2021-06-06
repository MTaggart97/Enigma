#include "src/Enigma/headers/Reflector.h"
#include "src/Enigma/headers/config.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using Enigma::Reflector;

Enigma::Reflector::Reflector(const REFLECTOR_CONFIG* r_config) noexcept(false) {
    // Copy each element into array (as data is in a struct)
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            rotor[i][0] = r_config->wiring[i][0];
            rotor[i][1] = r_config->wiring[i][1];
        }
    }
}

char Enigma::Reflector::get(const char x) {
    for (int i = 0; i < 13; i++) {
        if (rotor[i][0] == x) {
            return rotor[i][1];
        } else if (rotor[i][1] == x) {
            return rotor[i][0];
        }
    }
    return ' ';
}
