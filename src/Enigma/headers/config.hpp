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
#define ENIGMA_ROTOR_4 { {'e','s','o','v','p','z','j','a','y','q','u','i','r','h','x','l','n','f','t','g','k','d','c','m','w','b'}, 'j', 0 }
#define ENIGMA_ROTOR_5 { {'v','z','b','r','g','i','t','y','u','p','s','d','n','h','l','x','a','w','m','j','q','o','f','e','c','k'}, 'z', 0 }
#define ENIGMA_ROTOR_6 { {'j','p','g','v','o','u','m','f','y','q','b','e','n','h','z','r','d','k','a','s','x','l','i','c','t','w'}, 'z', 0 }
#define ENIGMA_ROTOR_7 { {'n','z','j','h','g','r','c','x','m','y','s','w','b','o','u','f','a','i','v','l','p','e','k','q','d','t'}, 'm', 0 }
#define ENIGMA_ROTOR_8 { {'f','k','q','h','t','l','x','o','c','b','j','s','p','d','z','r','a','m','e','w','n','i','u','y','g','v'}, 'm', 0 }

#define PLUGBOARD { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'}, {'m','n'}, {'o','p'}, {'q','r'}, {'s','t'}, {'u','v'}, {'w','x'}, {'y','z'} } }
#define PLUGBOARD_MISSING { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'} } }

#define REFLECTOR { { {'a','b'}, {'c','d'}, {'e','f'}, {'g','h'}, {'i','j'}, {'k','l'}, {'m','n'}, {'o','p'}, {'q','r'}, {'s','t'}, {'u','v'}, {'w','x'}, {'y','z'} } }
#define REFLECTOR_A { { {'a','e'}, {'b','j'}, {'c','m'}, {'d','z'}, {'f','l'}, {'g','y'}, {'h','x'}, {'i','v'}, {'k','w'}, {'n','r'}, {'o','q'}, {'p','u'}, {'s','t'} } }
#define REFLECTOR_B { { {'a','y'}, {'b','r'}, {'c','u'}, {'d','h'}, {'e','q'}, {'f','s'}, {'g','l'}, {'i','p'}, {'j','x'}, {'k','n'}, {'m','o'}, {'t','z'}, {'v','w'} } }
#define REFLECTOR_C { { {'a','f'}, {'b','v'}, {'c','p'}, {'d','j'}, {'e','i'}, {'g','o'}, {'h','y'}, {'k','r'}, {'l','z'}, {'m','x'}, {'n','w'}, {'q','t'}, {'s','u'} } }

#endif