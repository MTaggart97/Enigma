#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    char a = rotor1.reverse('e');
    rotor1.rotate(true);
    rotor1.encrypt('a');
    // After rotate, q -> r -> x -> w
    char w = rotor1.reverse('q');

    return (a != 'a' || w != 'w');
}
