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


unsigned long MLPrivateKey::getBitLength() const
{
    return 548;
}

unsigned long MLPrivateKey::getOutputLength() const
{
    return 128;
}



// Serialisation
ByteString MLPrivateKey::serialise() const
{
    ByteString len(128);

    return len.serialise();
}

bool MLPrivateKey::deserialise(ByteString& serialised)
{
    ByteString dE = ByteString::chainDeserialise(serialised);
    ByteString dLen = ByteString::chainDeserialise(serialised);

    if ((dE.size() == 0) ||
        (dLen.size() == 0))
    {
        return false;
    }


    return true;
}