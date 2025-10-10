//
// Created by root on 9/4/25.
//

#include "config.h"
#include "log.h"
#include "MLParameters.h"
#include <string.h>


// The type
/*static*/ const char* MLParameters::type = "Generic MLDSA parameters";

// Are the parameters of the given type?
bool MLParameters::areOfType(const char* inType)
{
    return (strcmp(type, inType) == 0);
}

// Serialisation
ByteString MLParameters::serialise() const
{
    ByteString len(bitLen);

    return e.serialise() + len.serialise();
}

bool MLParameters::deserialise(ByteString& serialised)
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

MLParameters::MLParameters(SecurityLevel level) : secLevel(level) {}

size_t MLParameters::getPublicKeySize() const {
    switch (secLevel) {
    case MLDSA_44: return 1312;
    case MLDSA_65: return 1952;
    case MLDSA_87: return 2592;
    default: return 0;
    }
}

size_t MLParameters::getPrivateKeySize() const {
    switch (secLevel) {
    case MLDSA_44: return 2560;
    case MLDSA_65: return 4032;
    case MLDSA_87: return 4896;
    default: return 0;
    }
}

size_t MLParameters::getSignatureSize() const {
    switch (secLevel) {
    case MLDSA_44: return 2420;
    case MLDSA_65: return 3366;
    case MLDSA_87: return 4595;
    default: return 0;
    }
}

MLParameters::SecurityLevel MLParameters::getSecurityLevel() const {
    return secLevel;
}
