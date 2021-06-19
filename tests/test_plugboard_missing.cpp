#include "PlugBoard.hpp"
#include "config.hpp"

using Enigma::PlugBoard;

int main() {
    PLUGBOARD_CONFIG p_config = PLUGBOARD_MISSING;

    PlugBoard pb{&p_config};
    char b = pb.get('a');
    char z = pb.get('z');

    return (b != 'b' || z != 'z');
}