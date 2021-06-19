#include "Reflector.hpp"
#include "config.hpp"

using Enigma::Reflector;

int main() {
    REFLECTOR_CONFIG r_config = REFLECTOR;
    Reflector r{&r_config};

    char b = r.encrypt('a');
    char w = r.encrypt('x');

    return (b != 'b' || w != 'w');
}