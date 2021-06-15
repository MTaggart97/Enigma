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

    char w = machine.encrypt('a');
    char u = machine.encrypt('a');
    char p = machine.encrypt('a');
    char h = machine.encrypt('a');
    char n = machine.encrypt('a');

    return (w != 'w' || u != 'u' || p != 'p' || h != 'h' || n != 'n');
}