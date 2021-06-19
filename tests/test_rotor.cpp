#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    rotor1.rotate(true);
    char k = rotor1.encrypt('a');

    return (k != 'k');
}
