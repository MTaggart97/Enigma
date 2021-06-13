#ifndef _ROTOR_H
#define _ROTOR_H

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
         * Given a character, encode it using this rotor. If
         * the second parameter is true, the rotor will
         * rotate.
         * 
         * @param   char    Character to encrypt
         * @param   bool    Wether or not to rotate
         * @return  Encrypted character
         */
        char encrypt(const char, const bool);
        /**
         * Checks if the rotor is on the notch or not.
         * 
         * @return  True if notched, false otherwise
         */
        bool on_notch();
        /**
         * Get the index of a given character in the rotor.
         * This takes into account the rotation of the rotor.
         * Returns the length of the rotor if the character
         * is not found
         * 
         * @param   c   Character to get index of
         * @return  The index of the character
         */
        int get_index(char c);

        char get(int pos);
    };
}

#endif