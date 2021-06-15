#include "config.hpp"
#include "EnigmaMachine.hpp"

using Enigma::EnigmaMachine;

int main() {
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD_MISSING;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = { {'a', 'j', 'd', 'k', 's', 'i', 'r', 'u', 'x', 'b', 'l', 'h', 'w', 't', 'm', 'c', 'q', 'g', 'z', 'n', 'p', 'y', 'f', 'v', 'o', 'e'}, 'e', 4 };
    ROTOR_CONFIG rotor_config_3 = { {'b', 'd', 'f', 'h', 'j', 'l', 'c', 'p', 'r', 't', 'x', 'v', 'z', 'n', 'y', 'e', 'i', 'w', 'g', 'a', 'k', 'm', 'u', 's', 'q', 'o'}, 'v', 21 };
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;
    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    char expected[23] = {'e','t','y','p','k','o','x','y',
                         'g','z','m','t','h','m','y','l',
                         'u','s','c','k','o','p','k'};
                 
    char actual[23];

    for (size_t i = 0; i < 23; i++) {
        actual[i] = machine.encrypt('a');
    }
    
    bool res = false;

    for (size_t i = 0; i < 23; i++) {
        res |= (expected[i] != actual[i]);
    }

    return res;
}