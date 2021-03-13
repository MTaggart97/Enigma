#include "src/Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main() {
    const std::string file{"../tests/resources/sample_plugboard.txt"};
    PlugBoard pb{file};

    char space = pb.get(' ');

    return space != ' ';
}