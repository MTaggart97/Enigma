#include <iostream>
#include "Enigma/headers/PlugBoard.h"

using Enigma::PlugBoard;

int main(const int , const char**) {
    const std::string file{"../src/resources/plugboard1.txt"};
    PlugBoard pb{file};

    std::string text;
    for(;;) {
        std::cout << "Enter the text you want to encrypt\n";
        std::cout << "Press '\\' and Enter to exit" << std::endl;
        std::getline(std::cin, text);
        std::cout << "Encrypted message is\n";
        for (size_t i = 0; i < text.size(); i++) {
            if (text.at(i) == '\\') {
                std::cout << std::endl;
                std::cout << "'\\' detected, exiting..." << std::endl;
                return 0;
            }
            std::cout << pb.get(text.at(i));
        }
        std::cout << std::endl;
    }
}
