#include "config.hpp"
#include "EnigmaMachine.hpp"

using Enigma::EnigmaMachine;

int main() {
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD_MISSING;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = ENIGMA_ROTOR_2;
    ROTOR_CONFIG rotor_config_3 = ENIGMA_ROTOR_3;
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;
    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    char expected[97] = {'w','u','p','h','n','w','o','i',
                         'u','s','q','h','t','u','k','m',
                         'n','u','n','y','r','g','z','s',
                         'g','p','t','r','c','i','h','f',
                         'w','j','c','t','c','z','p','c',
                         'f','s','i','c','q','z','c','e',
                         'j','v','w','s','r','h','h','d',
                         'u','j','r','c','h','i','p','o',
                         'n','i','p','w','z','m','z','n',
                         's','y','f','v','c','u','r','d',
                         'j','l','m','z','z','c','r','b',
                         'h','q','n','q','o','o','n','u',
                         'w'};

    char actual[97];

    for (size_t i = 0; i < 97; i++) {
        actual[i] = machine.encrypt('a');
    }
    
    bool res = false;

    for (size_t i = 0; i < 97; i++) {
        res |= (expected[i] != actual[i]);
    }

    return res;
}