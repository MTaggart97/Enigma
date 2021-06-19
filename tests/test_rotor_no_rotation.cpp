#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.encrypt('a');
    char m = rotor1.encrypt('c');
    char y = rotor1.encrypt('o');

    return (e != 'e' || m != 'm'  || y != 'y');
}
