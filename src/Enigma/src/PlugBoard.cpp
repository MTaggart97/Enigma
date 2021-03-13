#include "src/Enigma/headers/PlugBoard.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using Enigma::PlugBoard;

Enigma::PlugBoard::PlugBoard(const std::string file) {
    // TODO: Throw an exception if file does not exist
    read_file(file, plugboard);
}

char Enigma::PlugBoard::get(const char x) {
    int index = char_to_int(x);
    if (index < 0 || index >= 27) {
        index = 26;
    }
    return plugboard[index];
}

int Enigma::PlugBoard::char_to_int(char c) {
    return ((int) c) - 97;
}

void Enigma::PlugBoard::read_file(const std::string file, char* pb) {
    std::ifstream my_file;
    my_file.open(file);
    if (!my_file) {
        cout << "File not valid" << endl;
        return;
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
