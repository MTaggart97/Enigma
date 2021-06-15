/**
 * File containing the configurations for common rotors, plugboards
 * and reflectors. The schemas are as follows:
 * 
 * Rotor     → wiring, notch, ring setting
 * Plugboard → wiring
 * Reflector → wiring
 * 
 * Wiring can be found here, https://en.wikipedia.org/wiki/Enigma_rotor_details
 */

#ifndef _CONFIG_H
#define _CONFIG_H

/**
 * Struct storing the rotor configuration. The
 * rotor consists of the wiring, a notch and the
 * current offset.
 */
struct ROTOR_CONFIG {
    char wiring[26];
    char notch;
    int offset;
};

/**
 * Struct containing the plugboard configuration.
 * The plugboard just swaps letters. The wiring
 * is just an array containing a string of length
 * 2, where the 2 letters are swapped. It is possible
 * for a character not to be re-wired.
 */
struct PLUGBOARD_CONFIG {
    char wiring[13][2];
};

/**
 * Struct containing the reflector configuration. It
 * is very similar to a plugboard except that all
 * characters are swapped.
 */
struct REFLECTOR_CONFIG {
    char wiring[13][2];
};

struct MACHINE_CONFIG {
    PLUGBOARD_CONFIG* plugboard_config;
    ROTOR_CONFIG* rotor_config_1;
    ROTOR_CONFIG* rotor_config_2;
    ROTOR_CONFIG* rotor_config_3;
    REFLECTOR_CONFIG* reflector_config;
};

#define ALPHABET { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }

#define ENIGMA_ROTOR_1 { {'e', 'k', 'm', 'f', 'l', 'g', 'd', 'q', 'v', 'z', 'n', 't', 'o', 'w', 'y', 'h', 'x', 'u', 's', 'p', 'a', 'i', 'b', 'r', 'c', 'j'}, 'q', 0 }
#define ENIGMA_ROTOR_2 { {'a', 'j', 'd', 'k', 's', 'i', 'r', 'u', 'x', 'b', 'l', 'h', 'w', 't', 'm', 'c', 'q', 'g', 'z', 'n', 'p', 'y', 'f', 'v', 'o', 'e'}, 'e', 0 }
#define ENIGMA_ROTOR_3 { {'b', 'd', 'f', 'h', 'j', 'l', 'c', 'p', 'r', 't', 'x', 'v', 'z', 'n', 'y', 'e', 'i', 'w', 'g', 'a', 'k', 'm', 'u', 's', 'q', 'o'}, 'v', 0 }

#define PLUGBOARD { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'}, {'m','n'}, {'o','p'}, {'q','r'}, {'s','t'}, {'u','v'}, {'w','x'}, {'y','z'} } }
#define PLUGBOARD_MISSING { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'} } }

#define REFLECTOR { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'}, {'m','n'}, {'o','p'}, {'q','r'}, {'s','t'}, {'u','v'}, {'w','x'}, {'y','z'} } }
#define REFLECTOR_B { { {'a','y'}, {'b','r'}, {'c','u'}, {'d','h'}, {'e','q'}, {'f','s'}, {'g','l'}, {'i','p'}, {'j','x'}, {'k','n'}, {'m','o'}, {'t','z'}, {'v','w'} } }

#endif
