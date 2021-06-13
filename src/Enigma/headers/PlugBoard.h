#ifndef _PLUGBOARD_H
#define _PLUGBOARD_H

#include <cstddef>
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
         * Number of pairs of elements that are swapped.
         */
        size_t length;
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