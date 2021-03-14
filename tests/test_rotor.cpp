#include "src/Enigma/headers/Rotor.h"

using Enigma::Rotor;

int main() {
    const std::string file{"../tests/resources/Rotor1.txt"};

    Rotor rotor1{&file};

    char e = rotor1.get('a');
    char c = rotor1.get('y');

    return (e != 'e' || c != 'c');
}
