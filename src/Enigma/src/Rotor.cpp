#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/headers/config.h"
#include <fstream>

using Enigma::Rotor;

// TODO: Move to a utility class
std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
    return ltrim(rtrim(str, chars), chars);
}

Rotor::Rotor(const ROTOR_CONFIG* r_config) {
    for (int i = 0; i < 26; i++) {
        rotor[i] = r_config->wiring[i];
    }
    notch = r_config->notch;
    counter = r_config->offset;
}

char Rotor::get(const char c) {
    // Ensure index is > 0 and < 26
    int index = (26 + (char_to_int(c) - counter) % 26) % 26;
    char ch = rotor[index];
    rotate();
    return ch;
}

void Rotor::rotate() {
    ++counter;
}

int Rotor::char_to_int(char c) {
    return ((int) c) - 97;
}

void Rotor::set_notch(std::ifstream& file, int& n) {
    std::string line;
    std::getline(file, line);
    trim(line);
    n = char_to_int(line.at(0));
}

void Rotor::set_rotor(std::ifstream& file, char* rt) {
    std::string line;
    while (std::getline(file, line)) {
        trim(line);
        const char key = line.at(0);
        const char value = line.at(line.size() - 1);

        rt[char_to_int(key)] = value;
    }
}
