#ifndef _ENIGMA_MACHINE_H
#define _ENIGMA_MACHINE_H

#include "config.hpp"
#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

using Enigma::PlugBoard;
using Enigma::Rotor;
using Enigma::Reflector;

namespace Enigma {
    class EnigmaMachine {
    private:
        /**
         * Pointer to plugboard.
         */
        PlugBoard* plugboard;
        /**
         * Pointer to first rotor.
         */
        Rotor* rotor1;
        /**
         * Pointer to second rotor.
         */
        Rotor* rotor2;
        /**
         * Pointer to third rotor.
         */
        Rotor* rotor3;
        /**
         * Pointer to reflector.
         */
        Reflector* reflector;
    public:
        /**
         * Initialise the Enigma Machine.
         *
         * @param   config  Machine config
         */
        EnigmaMachine(const MACHINE_CONFIG*);
        /**
         * Destroys the pointers to each of the 
         * machines components.
         */
        ~EnigmaMachine();
        /**
         * Encrypts a given charater.
         *
         * @param   char    Character to encrypt
         * @return          The encrypted character
         */
        char encrypt(const char);
    };
}

#endif
