//
// Created by root on 9/25/25.
//

#ifndef _SOFTHSM_V2_OSSLMLKEYPAIR_H
#define _SOFTHSM_V2_OSSLMLKEYPAIR_H

#include "config.h"
#include "AsymmetricKeyPair.h"
#include "OSSLMLPublicKey.h"
#include "OSSLMLPrivateKey.h"

class OSSLMLKeyPair : public AsymmetricKeyPair
{
public:
    // Set the public key
    void setPublicKey(OSSLMLPublicKey& publicKey);

    // Set the private key
    void setPrivateKey(OSSLMLPrivateKey& privateKey);

    // Return the public key
    virtual PublicKey* getPublicKey();
    virtual const PublicKey* getConstPublicKey() const;

    // Return the private key
    virtual PrivateKey* getPrivateKey();
    virtual const PrivateKey* getConstPrivateKey() const;

private:
    // The public key
    OSSLMLPublicKey pubKey;

    // The private key
    OSSLMLPrivateKey privKey;
};

#endif // !_SOFTHSM_V2_OSSLMLKEYPAIR_H

