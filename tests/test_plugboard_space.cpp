#include "PlugBoard.h"
#include "config.h"

using Enigma::PlugBoard;

int main() {
    PLUGBOARD_CONFIG p_config = PLUGBOARD;

    PlugBoard pb{&p_config};
    char space = pb.get(' ');
    char space1 = pb.get('5');
    return (space != ' ' || space1 != ' ');
}