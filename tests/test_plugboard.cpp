#include "PlugBoard.hpp"
#include "config.hpp"

using Enigma::PlugBoard;

int main() {
    PLUGBOARD_CONFIG p_config = PLUGBOARD;
    PlugBoard pb{&p_config};

    char b = pb.get('a');
    char w = pb.get('x');

    return (b != 'b' || w != 'w');
}