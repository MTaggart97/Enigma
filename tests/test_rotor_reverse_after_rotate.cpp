#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    char a = rotor1.reverse('e');
    rotor1.encrypt('a', true);
    // After rotate, q -> r -> x
    char x = rotor1.reverse('q');

    return (a != 'a' || x != 'x');
}
