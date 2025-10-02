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

// Set the bit length
void MLPublicKey::setBitLength(const size_t inBitLen)
{
    bitLen = inBitLen;
}

// Get the bit length
size_t MLPublicKey::getBitLength() const
{
    return bitLen;
}

unsigned long MLPublicKey::getOutputLength() const
{
    return 0;
}


// Are the parameters of the given type?
bool MLPublicKey::areOfType(const char* inType)
{
    return (strcmp(type, inType) == 0);
}

// Serialisation
ByteString MLPublicKey::serialise() const
{
    ByteString len(bitLen);

    return e.serialise() + len.serialise();
}

bool MLPublicKey::deserialise(ByteString& serialised)
{
    ByteString dE = ByteString::chainDeserialise(serialised);
    ByteString dLen = ByteString::chainDeserialise(serialised);

    if ((dE.size() == 0) ||
        (dLen.size() == 0))
    {
        return false;
    }

    setBitLength(dLen.long_val());

    return true;
}