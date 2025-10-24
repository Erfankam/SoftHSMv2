//
// Created by root on 9/25/25.
//

#include "OSSLMLKeyPair.h"


// Set the public key
void OSSLMLKeyPair::setPublicKey(OSSLMLPublicKey& publicKey)
{
    pubKey = publicKey;
}

// Set the private key
void OSSLMLKeyPair::setPrivateKey(OSSLMLPrivateKey& privateKey)
{
    privKey = privateKey;
}

// Return the public key
PublicKey* OSSLMLKeyPair::getPublicKey()
{
    return &pubKey;
}

const PublicKey* OSSLMLKeyPair::getConstPublicKey() const
{
    return &pubKey;
}

// Return the private key
PrivateKey* OSSLMLKeyPair::getPrivateKey()
{
    return &privKey;
}

const PrivateKey* OSSLMLKeyPair::getConstPrivateKey() const
{
    return &privKey;
}

