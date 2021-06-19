#include "EnigmaMachine.hpp"
#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "config.hpp"
#include "utils.hpp"

using Enigma::EnigmaMachine;
using Enigma::PlugBoard;
using Enigma::Rotor;
using Enigma::Reflector;

Enigma::EnigmaMachine::EnigmaMachine(const MACHINE_CONFIG* m_config) {
    plugboard = new PlugBoard{m_config->plugboard_config};

    rotor1 = new Rotor{m_config->rotor_config_1};
    rotor2 = new Rotor{m_config->rotor_config_2};
    rotor3 = new Rotor{m_config->rotor_config_3};

    reflector = new Reflector{m_config->reflector_config};
}

Enigma::EnigmaMachine::~EnigmaMachine() {
    delete plugboard;
    delete rotor1;
    delete rotor2;
    delete rotor3;
    delete reflector;
}

char Enigma::EnigmaMachine::encrypt(const char character) {
    char result = plugboard->get(character);
    if (result == ' ') {
        return result;
    }

    // First Pass Through
    rotor1->rotate(true);
    result = rotor1->encrypt(result);

    rotor2->rotate(rotor1->on_notch());
    result = rotor2->encrypt(Enigma::Utils::int_to_char(rotor1->get_index(result)));
    
    rotor3->rotate(rotor2->on_notch());
    result = rotor3->encrypt(Enigma::Utils::int_to_char(rotor2->get_index(result)));

    // Reflector
    result = Enigma::Utils::int_to_char(rotor3->get_index(result));
    result = reflector->encrypt(result);

    // Second Pass Through
    result = rotor3->reverse(result);
    result = rotor2->reverse(result);
    result = rotor1->reverse(result);

    result = plugboard->get(result);
    return result;
}
