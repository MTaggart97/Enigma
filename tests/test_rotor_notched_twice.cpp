#include "Rotor.hpp"
#include "config.hpp"

using Enigma::Rotor;

int main() {
    ROTOR_CONFIG r_config = ENIGMA_ROTOR_1;
    Rotor rotor1{&r_config};

    // Rotate 16 times, i.e. one before the notch
    for (int i = 0; i < 16; i++) {
        rotor1.rotate(true);
        rotor1.encrypt('a');
    }
    bool not_notched1 = rotor1.on_notch();
    rotor1.rotate(true);
    rotor1.encrypt('a');
    bool notched1 = rotor1.on_notch();

    // Rotate 25 times, i.e. one before the notch
    for (int i = 0; i < 25; i++) {
        rotor1.rotate(true);
        rotor1.encrypt('a');
    }
    bool not_notched2 = rotor1.on_notch();
    rotor1.rotate(true);
    rotor1.encrypt('a');
    bool notched2 = rotor1.on_notch();

    return !notched1 || not_notched1 || !notched2 || not_notched2;
}
