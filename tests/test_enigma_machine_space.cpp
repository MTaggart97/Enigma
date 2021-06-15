#include "config.h"
#include "EnigmaMachine.h"

using Enigma::EnigmaMachine;

int main() {
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = ENIGMA_ROTOR_2;
    ROTOR_CONFIG rotor_config_3 = ENIGMA_ROTOR_3;
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;
    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    char s1 = machine.encrypt(' ');
    char s2 = machine.encrypt(' ');
    char s3 = machine.encrypt(' ');

    return (s1 != ' ' || s2 != ' ' || s3 != ' ');
}