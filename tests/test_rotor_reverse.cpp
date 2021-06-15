#include "Rotor.h"
#include "config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    char a = rotor1.reverse('e');

    return (a != 'a');
}
