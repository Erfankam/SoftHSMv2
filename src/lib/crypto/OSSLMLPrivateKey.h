//
// Created by root on 9/10/25.
//

#ifndef _SOFTHSM_V2_OSSLMLPRIVATEKEY_H
#define _SOFTHSM_V2_OSSLMLPRIVATEKEY_H

#include "config.h"
#include "MLPrivateKey.h"


class OSSLMLPrivateKey : public MLPrivateKey
{
public:
    // Constructors
    OSSLMLPrivateKey();

    //OSSLRSAPrivateKey(const RSA* inRSA);

    // Destructor
    virtual ~OSSLMLPrivateKey();

    // The type
    static const char* type;

    // Check if the key is of the given type
    virtual bool isOfType(const char* inType);

    // Setters for the RSA private key components
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
//    // Encode into PKCS#8 DER
//    virtual ByteString PKCS8Encode();
//
//    // Decode from PKCS#8 BER
//    virtual bool PKCS8Decode(const ByteString& ber);
//
//    // Set from OpenSSL representation
//    virtual void setFromOSSL(const RSA* inRSA);
//
//    // Retrieve the OpenSSL representation of the key
//    RSA* getOSSLKey();

private:
    // The internal OpenSSL representation
//    RSA* rsa;

    // Create the OpenSSL representation of the key
    void createOSSLKey();
};

#endif // !_SOFTHSM_V2_OSSLMLPRIVATEKEY_H

