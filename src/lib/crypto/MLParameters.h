//
// Created by root on 9/4/25.
//
#ifndef _SOFTHSM_V2_MLPARAMETERS_H
#define _SOFTHSM_V2_MLPARAMETERS_H

#include "config.h"
#include "ByteString.h"
#include "AsymmetricParameters.h"

class MLParameters : public AsymmetricParameters
{
public:
    // Base constructor
    MLParameters() : bitLen(0) { }

    // The type
    static const char* type;

    // Are the parameters of the given type?
    virtual bool areOfType(const char* inType);

    // Serialisation
    virtual ByteString serialise() const;
    virtual bool deserialise(ByteString& serialised);

private:
    ByteString e;
    size_t bitLen;
};

#endif // !_SOFTHSM_V2_MLPARAMETERS_H