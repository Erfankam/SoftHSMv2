//
// Created by root on 9/4/25.
//


#include "config.h"
#include "log.h"
#include "MLPrivateKey.h"
#include <string.h>

// Set the type
/*static*/ const char* MLPrivateKey::type = "Abstract MLDSA private key";

// Check if the key is of the given type
bool MLPrivateKey::isOfType(const char* inType)
{
    return !strcmp(type, inType);
}