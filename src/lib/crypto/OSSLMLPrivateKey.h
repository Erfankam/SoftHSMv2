//
// Created by root on 9/10/25.
//

#ifndef _SOFTHSM_V2_OSSLMLPRIVATEKEY_H
#define _SOFTHSM_V2_OSSLMLPRIVATEKEY_H

#include "config.h"
#include "MLPrivateKey.h"
#include <openssl/evp.h>

typedef EVP_PKEY MLDSA;

class OSSLMLPrivateKey : public MLPrivateKey
{
public:
    // Constructors
    OSSLMLPrivateKey();

    OSSLMLPrivateKey(const MLDSA* inMLDSA);

    // Destructor
    virtual ~OSSLMLPrivateKey();

    // The type
    static const char* type;

    // Check if the key is of the given type
    virtual bool isOfType(const char* inType);

    // Setters for the ML private key components


    // Encode into PKCS#8 DER
    virtual ByteString PKCS8Encode();

    // Decode from PKCS#8 BER
    virtual bool PKCS8Decode(const ByteString& ber);


    // Set from OpenSSL representation
    virtual void setFromOSSL(const MLDSA* inMLDSA);

    // Retrieve the OpenSSL representation of the key
    MLDSA* getOSSLKey();

private:
    // The internal OpenSSL representation
    MLDSA* mldsa;

    // Create the OpenSSL representation of the key
    void createOSSLKey();
};

#endif // !_SOFTHSM_V2_OSSLMLPRIVATEKEY_H

