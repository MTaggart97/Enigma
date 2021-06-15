#include "Reflector.h"
#include "config.h"

using Enigma::Reflector;

int main() {
    REFLECTOR_CONFIG r_config = REFLECTOR;
    Reflector r{&r_config};

    char b = r.get('a');
    char w = r.get('x');

    return (b != 'b' || w != 'w');
}