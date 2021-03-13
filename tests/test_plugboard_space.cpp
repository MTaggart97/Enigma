#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/src/FileNotFound.cpp"

using Enigma::PlugBoard;

int main() {
    const std::string file{"../tests/resources/sample_plugboard.txt"};
    try {
        PlugBoard pb{&file};
        char space = pb.get(' ');
        return space != ' ';
    } catch (const Enigma::FileNotFound &e) {
        return 1;
    }
}