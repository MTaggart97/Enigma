#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 3 times
    char a = rotor1.get(0);
    rotor1.encrypt('a', true);
    char b = rotor1.get(0);
    rotor1.encrypt('a', true);
    char c = rotor1.get(0);

    return (a != 'a' || b != 'b'  || c != 'c');
}
