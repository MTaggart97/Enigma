#ifndef _REFLECTOR_H
#define _REFLECTOR_H

#include "config.hpp"

namespace Enigma {
    class Reflector {
    private:
        /**
         * Stores the reflector settings in the form 'ab',
         * where a and b are swapped.
         */ 
        char rotor[13][2];
    public:
        Reflector(const REFLECTOR_CONFIG*) noexcept(false);
        /**
         * This will get the output of the reflector
         * for the given character.
         * 
         * @param   char    Input character
         * @return  Transformed character
         */
        char encrypt(const char);
    };
}

#endif