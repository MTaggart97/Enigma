#ifndef _PLUGBOARD_H
#define _PLUGBOARD_H

#include <iostream>
#include "src/Enigma/headers/config.h"

namespace Enigma {
    class PlugBoard {
    private:
        /**
         * Stores the plug board settings in the form 'ab',
         * where a and b are swapped.
         */ 
        char plugboard[13][2];
        /**
         * Takes a character and returns its position in the 
         * alphabet. It is assumed that the characters encoding is
         * such that 'a' = 97, 'b' = 98 etc. This only works for 
         * lower case letters.
         *
         * @param   char    Character to convert
         * @return  The position of the character in the alphabet
         */
        int char_to_int(char);
    public:
        PlugBoard(const PLUGBOARD_CONFIG*) noexcept(false);
        /**
         * This will get the output of the plugboard
         * for the given character.
         * 
         * @param   char    Input character
         * @return  Transformed character
         */
        char get(const char);
    };
}

#endif