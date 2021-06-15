#include <iostream>
#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "config.hpp"

using Enigma::EnigmaMachine;

int main(const int , const char**) {
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = ENIGMA_ROTOR_2;
    ROTOR_CONFIG rotor_config_3 = ENIGMA_ROTOR_3;
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;
    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    std::string text;
    for(;;) {
        std::cout << "Enter the text you want to encrypt\n";
        std::cout << "Press '\\' and Enter to exit" << std::endl;
        std::getline(std::cin, text);
        std::cout << "Encrypted message is\n";
        for (size_t i = 0; i < text.size(); i++) {
            if (text.at(i) == '\\') {
                std::cout << std::endl;
                std::cout << "'\\' detected, exiting..." << std::endl;
                return 0;
            }
            std::cout << machine.encrypt(text.at(i));
        }
        std::cout << std::endl;
    }
}
