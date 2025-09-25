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
