#ifndef _ENIGMA_MACHINE_H
#define _ENIGMA_MACHINE_H

#include "src/Enigma/headers/config.h"

namespace Enigma {
    class EnigmaMachine {
    public:
        EnigmaMachine(const MACHINE_CONFIG*);
        char encrypt(const char);
    };
}

#endif
