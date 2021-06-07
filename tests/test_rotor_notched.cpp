#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 25 times
    for (int i = 0; i < 25; i++) {
        rotor1.get('a', true);
    }
    bool not_notched = rotor1.on_notch();
    rotor1.get('a', true);
    bool notched = rotor1.on_notch();

    return notched && !not_notched;
}