#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    rotor1.rotate(true);
    char k = rotor1.encrypt('a');
    rotor1.rotate(true);
    char l = rotor1.encrypt('c');
    rotor1.rotate(true);
    char u = rotor1.encrypt('o');

    return (k != 'k' || l != 'l'  || u != 'u');
}
