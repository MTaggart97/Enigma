#include "Rotor.h"
#include "config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char e = rotor1.quick_encrypt('a');
    char m = rotor1.quick_encrypt('c');
    char g = rotor1.quick_encrypt('f');

    return (e != 'e' || m != 'm'  || g != 'g');
}
