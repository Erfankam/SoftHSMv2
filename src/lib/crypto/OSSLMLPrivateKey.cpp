//
// Created by root on 9/10/25.
//


#include "config.h"
#include "log.h"
#include "OSSLComp.h"
#include "OSSLMLPrivateKey.h"
#include "OSSLUtil.h"
#include <openssl/bn.h>
#include <openssl/x509.h>
#ifdef WITH_FIPS
#include <openssl/fips.h>
#endif
#include <string.h>

// Constructors
OSSLMLPrivateKey::OSSLMLPrivateKey()
{
    mldsa = NULL;
}

bool OSSLMLPrivateKey::isOfType(const char* inType) {
    return !strcmp(type, inType);
}


OSSLMLPrivateKey::OSSLMLPrivateKey(const MLDSA* inMLDSA)
{
    mldsa = NULL;

    setFromOSSL(inMLDSA);
}


// Destructor
OSSLMLPrivateKey::~OSSLMLPrivateKey()
{
    mldsa = NULL;
}

ByteString OSSLMLPrivateKey::PKCS8Encode()
{
    ByteString b;
    return b;
}

bool OSSLMLPrivateKey::PKCS8Decode(const ByteString& ber)
{
    return true;
}

void OSSLMLPrivateKey::setFromOSSL(const MLDSA* inMLDSA)
{
    inMLDSA = NULL;
}

MLDSA* OSSLMLPrivateKey::getOSSLKey()
{
    return mldsa;
}




// The type
/*static*/ const char* OSSLMLPrivateKey::type = "OpenSSL MLDSA Private Key";
