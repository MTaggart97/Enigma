#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char a = rotor1.get(20);
    rotor1.encrypt('a', true);
    char p = rotor1.get(20);
    rotor1.encrypt('a', true);
    char s = rotor1.get(20);

    return (a != 'a' || p != 'p'  || s != 's');
}
