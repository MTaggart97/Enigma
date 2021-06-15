#ifndef _ENIGMA_MACHINE_H
#define _ENIGMA_MACHINE_H

#include "config.h"
#include "PlugBoard.h"
#include "Rotor.h"
#include "Reflector.h"

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
        ~EnigmaMachine();
        char encrypt(const char);
    };
}

#endif
