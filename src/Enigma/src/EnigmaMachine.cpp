#include "src/Enigma/headers/EnigmaMachine.h"
#include "src/Enigma/headers/config.h"

using Enigma::EnigmaMachine;

Enigma::EnigmaMachine::EnigmaMachine(const MACHINE_CONFIG* m_config) {

}

char Enigma::EnigmaMachine::encrypt(const char character) {
    return character;
}
