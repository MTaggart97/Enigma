#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/src/FileNotFound.cpp"

using Enigma::PlugBoard;

int main() {
    const std::string file{"i_do_no_exist.404"};
    try {
        PlugBoard pb{&file};
        return 1;
    } catch (const Enigma::FileNotFound &e) {
        return 0;
    }
}