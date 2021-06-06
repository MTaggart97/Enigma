#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.get('a');
    char k = rotor1.get('c');
    char o = rotor1.get('o');

    return (e != 'e' || k != 'k'  || o != 'o');
}
