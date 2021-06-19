#include <iostream>
#include <fstream>
#include <string>
#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "config.hpp"

using Enigma::EnigmaMachine;

static void show_usage(const std::string name) {
    std::cerr << "Usage: " << name << " <option(s)> <text to encrypt>"
              << "\n\tOptions:\n"
              << "\t-h,--help\t\t\tShow this help message\n"
              << "\t-f,--file {FILE}\t\tFile to encrypt\n"
              << "\t-d,--destination {DESTINATION}\tFile to write output to\n"
              << "\t-p {1, 2}\t\t\tPlugboard Config\n"
              << "\t-r1 {1, 2, 3, 4, 5, 6, 7, 8}\tRotor 1 Config\n"
              << "\t-r2 {1, 2, 3, 4, 5, 6, 7, 8}\tRotor 2 Config\n"
              << "\t-r3 {1, 2, 3, 4, 5, 6, 7, 8}\tRotor 3 Config\n"
              << "\t-refl {S, A, B, C}\t\tReflector Config"
              << std::endl;
}

int main(const int argc, const char** argv) {
    if (argc < 2) {
        show_usage(argv[0]);
        return 1;
    }
    // Set up Enigma Machine
    PLUGBOARD_CONFIG plugboard_config = PLUGBOARD;
    ROTOR_CONFIG rotor_config_1 = ENIGMA_ROTOR_1;
    ROTOR_CONFIG rotor_config_2 = ENIGMA_ROTOR_2;
    ROTOR_CONFIG rotor_config_3 = ENIGMA_ROTOR_3;
    REFLECTOR_CONFIG reflector_config = REFLECTOR_B;

    std::ifstream in_file;
    std::fstream out_file;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            show_usage(argv[0]);
            return 1;
        } else if (arg == "-f" || arg == "--file") {
            arg = argv[++i];    // File name
            in_file.open(arg, std::ios::in | std::ios::app);
        } else if (arg == "-d" || arg == "--destination") {
            arg = argv[++i];    // Destination
            out_file.open(arg, std::ios::out);
        } else if (arg == "-p") {
            arg = argv[++i];    // Plugboard
            if (arg == "2") {
                plugboard_config = PLUGBOARD_MISSING;
            }
        } else if (arg == "-r1") {
            arg = argv[++i];    // Rotor 1
            if (arg == "2") {
                rotor_config_1 = ENIGMA_ROTOR_2;
            } else if (arg == "3") {
                rotor_config_1 = ENIGMA_ROTOR_3;
            }
        } else if (arg == "-r2") {
            arg = argv[++i];    // Rotor 2
            if (arg == "1") {
                rotor_config_2 = ENIGMA_ROTOR_1;
            } else if (arg == "3") {
                rotor_config_2 = ENIGMA_ROTOR_3;
            }
        } else if (arg == "-r3") {
            arg = argv[++i];    // Rotor 3
            if (arg == "1") {
                rotor_config_3 = ENIGMA_ROTOR_1;
            } else if (arg == "2") {
                rotor_config_3 = ENIGMA_ROTOR_2;
            }
        } else if (arg == "-refl") {
            arg = argv[++i];    // Reflector
            if (arg == "S") {
                reflector_config = REFLECTOR;
            }
        }
    }

    MACHINE_CONFIG m_config = { &plugboard_config, &rotor_config_1, &rotor_config_2, &rotor_config_3, &reflector_config };

    EnigmaMachine machine{&m_config};

    std::streambuf* in_buffer;
    if (in_file.is_open()) {
        in_buffer = in_file.rdbuf();
        std::cin.rdbuf(in_buffer);
    }

    std::streambuf* out_buffer;
    if (out_file.is_open()) {
        out_buffer = out_file.rdbuf();
        std::cout.rdbuf(out_buffer);
    }

    if (!in_file.is_open()) {
        size_t pos = 0;
        while(argv[argc - 1][pos]) {
            std::cout << machine.encrypt(argv[argc - 1][pos]);
            ++pos;
        }
    } else {
        while (std::cin.peek() != EOF) {
            std::cout << machine.encrypt(std::cin.get());
        }
    }

    std::cout << std::endl;
    if (in_file.is_open()) {
        in_file.close();
    }
    if (out_file.is_open()) {
        out_file.close();
    }

    return 0;
}
