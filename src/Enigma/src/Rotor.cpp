#include "src/Enigma/headers/Rotor.h"
#include "src/Enigma/src/FileNotFound.cpp"
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

Rotor::Rotor(const std::string* file) {
    read_file(file, rotor, notch);
}

char Rotor::get(const char c) {
    return rotor[char_to_int(c)];
}

void Rotor::rotate() {

}

int Rotor::char_to_int(char c) {
    return ((int) c) - 97;
}

void Rotor::read_file(const std::string* file, char* rt, int& n) {
    std::ifstream my_file;
    my_file.open(*file);
    if (!my_file) {
        throw Enigma::FileNotFound(file);
    }
    std::string line;
    while (std::getline(my_file, line)) {
        // Check if line is Notch or Permtations
        if (Rotor::NOTCH.compare(line)) {
            set_notch(my_file, n);
        } else if (Rotor::PERMUTATIONS.compare(line)) {
            set_rotor(my_file, rt);
        }
    }
    my_file.close();
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
