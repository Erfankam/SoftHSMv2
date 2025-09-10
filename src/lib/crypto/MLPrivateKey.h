//
// Created by root on 9/4/25.
//
#ifndef _SOFTHSM_V2_MLPRIVATEKEY_H
#define _SOFTHSM_V2_MLPRIVATEKEY_H

#include "config.h"
#include "PrivateKey.h"

class MLPrivateKey : public PrivateKey
{
public:
    // The type
    static const char* type;

    // Check if the key is of the given type
    virtual bool isOfType(const char* inType);

//    // Get the bit length
//    virtual unsigned long getBitLength() const;
//
//    // Get the output length
//    virtual unsigned long getOutputLength() const;
//
//    // Setters for the RSA private key components
//    virtual void setP(const ByteString& inP);
//    virtual void setQ(const ByteString& inQ);
//    virtual void setPQ(const ByteString& inPQ);
//    virtual void setDP1(const ByteString& inDP1);
//    virtual void setDQ1(const ByteString& inDQ1);
//    virtual void setD(const ByteString& inD);
//
//    // Setters for the RSA public key components
//    virtual void setN(const ByteString& inN);
//    virtual void setE(const ByteString& inE);
//
//    // Getters for the RSA private key components
//    virtual const ByteString& getP() const;
//    virtual const ByteString& getQ() const;
//    virtual const ByteString& getPQ() const;
//    virtual const ByteString& getDP1() const;
//    virtual const ByteString& getDQ1() const;
//    virtual const ByteString& getD() const;
//
//    // Getters for the RSA public key components
//    virtual const ByteString& getN() const;
//    virtual const ByteString& getE() const;

    // Serialisation
    virtual ByteString serialise() const;
    virtual bool deserialise(ByteString& serialised);

protected:
//    // Private components
//    ByteString p,q,pq,dp1,dq1,d;
//
//    // Public components
//    ByteString n,e;
};

#endif // !_SOFTHSM_V2_MLPRIVATEKEY_H

