#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.get('a', false);
    char m = rotor1.get('c', true);
    char w = rotor1.get('o', false);

    return (e != 'e' || m != 'm'  || w != 'w');
}
