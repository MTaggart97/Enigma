#include "Rotor.h"
#include "config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char k = rotor1.encrypt('a', true);
    char l = rotor1.encrypt('c', true);
    char u = rotor1.encrypt('o', true);

    return (k != 'k' || l != 'l'  || u != 'u');
}
