#include "src/Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main() {
    const std::string file{"../tests/resources/sample_plugboard.txt"};
    PlugBoard pb{file};
    
    char b = pb.get('a');
    char w = pb.get('x');

    return (b != 'b' || w != 'w');
}