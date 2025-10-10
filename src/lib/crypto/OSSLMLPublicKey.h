//
// Created by root on 9/10/25.
//

/*****************************************************************************
 OSSLRSAPublicKey.h

 OpenSSL RSA public key class
 *****************************************************************************/

#ifndef _SOFTHSM_V2_OSSLMLPUBLICKEY_H
#define _SOFTHSM_V2_OSSLMLPUBLICKEY_H

#include "config.h"
#include "MLPublicKey.h"
#include <openssl/evp.h>

typedef EVP_PKEY MLDSA;


class OSSLMLPublicKey : public MLPublicKey
{
public:
    // Constructors
    OSSLMLPublicKey();

    OSSLMLPublicKey(const MLDSA* inMLDSA);

    // Destructor
    virtual ~OSSLMLPublicKey();

    // The type
    static const char* type;



    // // Check if the key is of the given type
    virtual bool isOfType(const char* inType);

    // // Setters for the RSA public key components
    // virtual void setN(const ByteString& inN);
    // virtual void setE(const ByteString& inE);
    //
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

#endif // !_SOFTHSM_V2_OSSLMLPUBLICKEY_H


