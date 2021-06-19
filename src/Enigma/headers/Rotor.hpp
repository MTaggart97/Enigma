#ifndef _ROTOR_H
#define _ROTOR_H

#include "config.hpp"

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
    public:
        Rotor(const ROTOR_CONFIG*) noexcept(false);
        /**
         * Given a character, encode it using this rotor.
         * 
         * @param   char    Character to encrypt
         * @return  Encrypted character
         */
        char encrypt(const char);
        /**
         * Rotates the rotor if parameter is true.
         *
         * @param   bool    Flag that determines if to rotate
         */
        void rotate(bool);
        /**
         * Checks if the rotor is on the notch or not.
         * 
         * @return  True if notched, false otherwise
         */
        bool on_notch();
        /**
         * Get the index of a given character in the alphabet. 
         * This takes into account the rotation of the rotor. 
         * 
         * @param   c   Character to get index of
         * @return      The index of the character
         */
        int get_index(char c);
        /**
         * Encrypts the given character in the reverse 
         * direction. This takes into account the 
         * rotation of the rotor. It returns the character
         * of the aplhabet in the position of the rotor.
         * 
         * @param   c   Character to encrypt
         * @return      The encrypted character
         */
        char reverse(char c);
    };
}

#endif