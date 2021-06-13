#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.encrypt('a', true);
    char k = rotor1.encrypt('c', true);
    char o = rotor1.encrypt('o', true);

    return (e != 'e' || k != 'k'  || o != 'o');
}
