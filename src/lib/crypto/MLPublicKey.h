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

    // Get the bit length
    virtual unsigned long getBitLength() const;

    // Get the output length
    virtual unsigned long getOutputLength() const;

    // Setters for the RSA public key components
    virtual void setN(const ByteString& inN);
    virtual void setE(const ByteString& inE);

    // Getters for the RSA public key components
    virtual const ByteString& getN() const;
    virtual const ByteString& getE() const;

    // Serialisation
    virtual ByteString serialise() const;
    virtual bool deserialise(ByteString& serialised);

protected:
    // Public components
    ByteString n,e;
};

#endif // !_SOFTHSM_V2_MLPUBLICKEY_H

