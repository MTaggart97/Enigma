#ifndef _ENIGMA_MACHINE_H
#define _ENIGMA_MACHINE_H

#include "src/Enigma/headers/config.h"
#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/Reflector.h"

using Enigma::PlugBoard;
using Enigma::Rotor;
using Enigma::Reflector;

namespace Enigma {
    class EnigmaMachine {
    private:
        PlugBoard* plugboard;
        Rotor* rotor1;
        Rotor* rotor2;
        Rotor* rotor3;
        Reflector* reflector;
    public:
        EnigmaMachine(const MACHINE_CONFIG*);
        char encrypt(const char);
    };
}

#endif
