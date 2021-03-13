#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/src/FileNotFound.cpp"

using Enigma::PlugBoard;

int main() {
    const std::string file{"../tests/resources/sample_plugboard.txt"};
    try {
        PlugBoard pb{&file};
    
        char b = pb.get('a');
        char w = pb.get('x');

        return (b != 'b' || w != 'w');
    } catch(const Enigma::FileNotFound& e) {
        return 1;
    }
}