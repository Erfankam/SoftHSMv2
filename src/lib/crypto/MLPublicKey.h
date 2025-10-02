//
// Created by root on 9/4/25.
//

#ifndef _SOFTHSM_V2_MLPUBLICKEY_H
#define _SOFTHSM_V2_MLPUBLICKEY_H

#include "config.h"
#include "PublicKey.h"

class MLPublicKey : public PublicKey
{
public:
    // The type
    static const char* type;

    // Check if the key is of the given type
    virtual bool isOfType(const char* inType);

    // Set the bit length
    void setBitLength(const size_t inBitLen);

    // Get the bit length
    virtual unsigned long getBitLength() const;

    // Get the output length
    virtual unsigned long getOutputLength() const;


    // Are the parameters of the given type?
    virtual bool areOfType(const char* inType);


    // Serialisation
    virtual ByteString serialise() const;
    virtual bool deserialise(ByteString& serialised);

protected:
    // Public components
    ByteString n,e;
    size_t bitLen;
};

#endif // !_SOFTHSM_V2_MLPUBLICKEY_H

