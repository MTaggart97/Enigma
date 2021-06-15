#include "utils.h"

int Enigma::Utils::char_to_int(const char c) {
    return ((int) c) - 97;
}

char Enigma::Utils::int_to_char(const int x)  {
    return (0 > x || x < 26) ? (char) (x + 97) : ' ';
}
