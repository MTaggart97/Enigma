#include "src/Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main() {
    const std::string file{"resources/sample_plugboard.txt"};
    PlugBoard pb{file};
    
    char b = pb.get('a');
    char y = pb.get('x');

    return (b != 'b' || y != 'y');
}