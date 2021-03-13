#include <iostream>
#include "Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main(const int , const char**) {
    const std::string file{"../src/resources/plugboard1.txt"};
    PlugBoard pb{file};

    char b = pb.get('a');
    char y = pb.get('x');

    std::cout << "a maps to " << b << std::endl;
    std::cout << "x maps to " << y << std::endl;
}
