#ifndef _PLUGBOARD_H
#define _PLUGBOARD_H

#include <iostream>

namespace Enigma {
    class PlugBoard {
    private:
        char plugboard[26];
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
        /**
         * Reads a file and stores contents in character 
         * array. The file should be of the form: 
         * 
         * <character>: <character>
         * 
         * where the characters correspond to the mapping 
         * the plugboard implements. Note that only half of 
         * the alphabet is needed as the mapping is two-way.
         * 
         * @param   std::string     Name of file
         * @param   char*           Array to store mappings
         */
        void read_file(const std::string, char*);
    public:
        PlugBoard(const std::string);
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