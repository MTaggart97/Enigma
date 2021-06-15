#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.encrypt('a', false);
    char f = rotor1.encrypt('c', true);
    char h = rotor1.encrypt('o', false);

    return (e != 'e' || f != 'f'  || h != 'h');
}
