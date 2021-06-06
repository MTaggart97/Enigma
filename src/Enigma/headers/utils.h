/**
 * Collection of utility functions.
 */

#ifndef _UTILS_H
#define _UTILS_H

namespace Enigma {
    namespace Utils {
        /**
         * Takes a character and returns its position in the 
         * alphabet. It is assumed that the characters encoding is
         * such that 'a' = 97, 'b' = 98 etc. This only works for 
         * lower case letters.
         *
         * @param   char    Character to convert
         * @return  The position of the character in the alphabet
         */
        int char_to_int(char c) {
            return ((int) c) - 97;
        }
        /**
         * Takes an integer and returns the letter (in lower case)
         * in that position. If out of range, a black space is
         * returned.
         * 
         * @param   int Position of character in alphabet
         * @return  Character in alphabet or space
         */
        char int_to_char(int x) {
            return (0 > x || x < 26) ? ' ' : (char) (x + 97);
        }
    }
}

#endif