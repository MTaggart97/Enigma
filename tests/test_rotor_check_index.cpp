#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    int p1 = rotor1.get_index('a');
    rotor1.rotate(true);
    rotor1.encrypt('a');
    int p2 = rotor1.get_index('a');
    rotor1.rotate(true);
    rotor1.encrypt('a');
    int p3 = rotor1.get_index('a');

    return (p1 != 0 || p2 != 25 || p3 != 24);
}
