#include "src/Enigma/headers/PlugBoard.h"
#include "src/Enigma/src/FileNotFound.cpp"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using Enigma::PlugBoard;

Enigma::PlugBoard::PlugBoard(const std::string* file) noexcept(false) {
    read_file(file, plugboard);
}

char Enigma::PlugBoard::get(const char x) {
    int index = char_to_int(x);
    if (index < 0 || index >= 27) {
        index = 26;
    }
    return plugboard[index];
}

// TODO: Move to a utility class
int Enigma::PlugBoard::char_to_int(char c) {
    return ((int) c) - 97;
}

void Enigma::PlugBoard::read_file(const std::string* file, char* pb)  noexcept(false) {
    std::ifstream my_file;
    my_file.open(*file);
    if (!my_file) {
        throw Enigma::FileNotFound(file);
    }
    std::string line;
    while (std::getline(my_file, line)) {
        const char key = line.at(0);
        const char value = line.at(line.size() - 1);

        pb[char_to_int(key)] = value;
        pb[char_to_int(value)] = key;
    }
    pb[26] = ' ';
    my_file.close();
}
