#ifndef _ROTOR_H
#define _ROTOR_H

#include <iostream>
#include <fstream>
#include "src/Enigma/headers/config.h"

namespace Enigma {
    class Rotor {
    private:
        /**
         * Stores the rotor configuration.
         */
        char rotor[26];
        /**
         * Notch used to indicate when the
         * rotor sends a signal to the next
         * rotor to rotate.
         */
        int notch;
        /**
         * Counter used to keep track of the
         * rotors position.
         */
        int counter;
        /**
         * Rotates the rotor.
         */
        void rotate();
    public:
        Rotor(const ROTOR_CONFIG*) noexcept(false);
        /**
         * Given a character, encode it using this rotor.
         */
        char get(const char);
    };
}

#endif