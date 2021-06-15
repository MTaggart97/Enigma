#include "Rotor.h"
#include "config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    char k = rotor1.encrypt('a', true);

    return (k != 'k');
}
