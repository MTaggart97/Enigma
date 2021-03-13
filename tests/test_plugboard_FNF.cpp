#include "src/Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main() {
    const std::string file{"i_do_no_exist.404"};
    try {
        PlugBoard pb{file};
        return 1;
    } catch (Enigma::Exceptions::FileNotFound e) {
        return 0;
    }
}