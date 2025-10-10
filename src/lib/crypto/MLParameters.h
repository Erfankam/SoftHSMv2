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

    enum SecurityLevel {
        MLDSA_44,
        MLDSA_65,
        MLDSA_87
    };


    // Base constructor
    MLParameters() : bitLen(0) { }
    MLParameters(SecurityLevel);

    // The type
    static const char* type;

    // Are the parameters of the given type?
    virtual bool areOfType(const char* inType);

    // Serialisation
    virtual ByteString serialise() const;
    virtual bool deserialise(ByteString& serialised);

    size_t getPublicKeySize() const;
    size_t getPrivateKeySize() const;
    size_t getSignatureSize() const;
    SecurityLevel getSecurityLevel() const;

private:
    ByteString e;
    size_t bitLen;
    SecurityLevel secLevel;
};

#endif // !_SOFTHSM_V2_MLPARAMETERS_H