//
// Created by root on 9/10/25.
//

#include "config.h"
#include "log.h"
#include "OSSLComp.h"
#include "OSSLMLPublicKey.h"
#include "OSSLUtil.h"
#include <string.h>
#include <openssl/bn.h>

OSSLMLPublicKey::OSSLMLPublicKey()
{
    mldsa = NULL;
}

OSSLMLPublicKey::OSSLMLPublicKey(const MLDSA* inType)
{
    mldsa = NULL;
    setFromOSSL(inType);
}

// Destructor
OSSLMLPublicKey::~OSSLMLPublicKey()
{
    mldsa = NULL;
}

// The type
/*static*/ const char* OSSLMLPublicKey::type = "OpenSSL MLDSA Public Key";

// Check if the key is of the given type
bool OSSLMLPublicKey::isOfType(const char* inType)
{
    return !strcmp(type, inType);
}

void OSSLMLPublicKey::setFromOSSL(const MLDSA* inMLDSA)
{
    unsigned char pub[1952];  // ML-DSA-65 public key size
    size_t pub_len = sizeof(pub);
    EVP_PKEY_get_octet_string_param(inMLDSA, "pub", pub, pub_len, &pub_len);
}

// Retrieve the OpenSSL representation of the key
MLDSA* OSSLMLPublicKey::getOSSLKey()
{
    return mldsa;
}
