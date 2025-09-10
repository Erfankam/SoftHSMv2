//
// Created by root on 9/4/25.
//
#include "config.h"
#include "log.h"
#include "MLPublicKey.h"
#include <string.h>

// Set the type
/*static*/ const char* MLPublicKey::type = "Abstract MLDSA public key";

// Check if the key is of the given type
bool MLPublicKey::isOfType(const char* inType)
{
    return !strcmp(type, inType);
}