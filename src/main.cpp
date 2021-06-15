#include <iostream>
#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "config.hpp"

using Enigma::EnigmaMachine;

int main(const int argc, const char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " 'text to encrypt'" << std::endl;
        return 1;
    }
    // Set up Enigma Machine
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = ENIGMA_ROTOR_2;
    ROTOR_CONFIG rotor_config_3 = ENIGMA_ROTOR_3;
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;
    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    size_t pos = 0;
    while(argv[1][pos]) {
        std::cout << machine.encrypt(argv[1][pos]);
        ++pos;
    }
    std::cout << std::endl;
    return 0;
}
