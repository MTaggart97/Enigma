#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/headers/config.h"

using Enigma::PlugBoard;

int main() {
    PLUGBOARD_CONFIG p_config = PLUGBOARD_MISSING;

    PlugBoard pb{&p_config};
    char space = pb.get(' ');
    char space1 = pb.get('8');

    return (space != ' ' || space1 != ' ');
}