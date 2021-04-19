#include "src/Enigma/headers/Rotor.h"

using Enigma::Rotor;

int main() {
    const std::string file{"../tests/resources/Rotor1.txt"};

    Rotor rotor1{&file};

    // Rotate 3 times
    char e = rotor1.get('a');
    char k = rotor1.get('c');
    char o = rotor1.get('o');

    return (e != 'e' || k != 'k'  || o != 'o');
}
