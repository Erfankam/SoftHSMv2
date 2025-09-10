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
}


// Destructor
OSSLMLPrivateKey::~OSSLMLPrivateKey()
{
}

// The type
/*static*/ const char* OSSLMLPrivateKey::type = "OpenSSL MLDSA Private Key";
