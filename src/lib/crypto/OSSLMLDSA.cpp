//
// Created by root on 9/4/25.
//

#include "config.h"
#include "log.h"
#include "OSSLMLDSA.h"
#include "OSSLUtil.h"
#include "CryptoFactory.h"
#include "MLParameters.h"
#include "OSSLRSAKeyPair.h"
#include <algorithm>
#include <OSSLMLKeyPair.h>

OSSLMLDSA::OSSLMLDSA() {
}

bool OSSLMLDSA::generateKeyPair(AsymmetricKeyPair** ppKeyPair, AsymmetricParameters* parameters, RNG* rng /*rng = NULL */)
{
    // Check parameters
    if ((ppKeyPair == NULL) ||
        (parameters == NULL))
    {
        return false;
    }

    if (!parameters->areOfType(MLParameters::type))
    {
        ERROR_MSG("Invalid parameters supplied for MLDSA key generation");

        return false;
    }

    MLParameters* params = (MLParameters*) parameters;

    //FIXME: use parametrized value for security level.
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_from_name(NULL, "ML-DSA-44", NULL);
    EVP_PKEY *evpKeyPair = NULL;

    if (!EVP_PKEY_keygen_init(ctx))
    {
        ERROR_MSG("RSA key initialization failed (%s)", ctx);
        EVP_PKEY_CTX_free(ctx);
        ctx = NULL;

        return false;
    }

    if (!EVP_PKEY_generate(ctx, &evpKeyPair))
    {
        ERROR_MSG("RSA key generation failed (%s)", ctx);
        EVP_PKEY_CTX_free(ctx);
        ctx = NULL;

        return false;
    }

    // Create an asymmetric key-pair object to return
    OSSLMLKeyPair* kp = new OSSLMLKeyPair();

    ((OSSLMLPublicKey*) kp->getPublicKey())->setFromOSSL(evpKeyPair);
    ((OSSLMLPrivateKey*) kp->getPrivateKey())->setFromOSSL(evpKeyPair);

    *ppKeyPair = kp;

    // Release the key
    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(evpKeyPair);
    evpKeyPair = NULL;

    return true;



    return true;

}

bool OSSLMLDSA::sign(PrivateKey* privateKey, const ByteString& dataToSign, ByteString& signature, const AsymMech::Type mechanism, const void* param /* = NULL */, const size_t paramLen/* = 0 */)
{
    return false;
}

bool OSSLMLDSA::signInit(PrivateKey* privateKey, const AsymMech::Type mechanism, const void* param /* = NULL */, const size_t paramLen /* = 0 */)
{
    return false;
}

bool OSSLMLDSA::signUpdate(const ByteString& dataToSign)
{
    return false;
}
bool OSSLMLDSA::signFinal(ByteString& signature)
{
    return false;
}

bool OSSLMLDSA::verify(PublicKey* publicKey, const ByteString& originalData, const ByteString& signature, const AsymMech::Type mechanism, const void* param /* = NULL */, const size_t paramLen/* = 0 */)
{
    return false;
}

bool OSSLMLDSA::verifyInit(PublicKey* publicKey, const AsymMech::Type mechanism, const void* param /* = NULL */, const size_t paramLen /* = 0 */)
{
    return false;
}
bool OSSLMLDSA::verifyUpdate(const ByteString& originalData)
{
    return false;
}

bool OSSLMLDSA::verifyFinal(const ByteString& signature)
{
    return false;
}

bool OSSLMLDSA::encrypt(PublicKey* publicKey, const ByteString& data, ByteString& encryptedData, const AsymMech::Type padding)
{
    return false;
}

bool OSSLMLDSA::decrypt(PrivateKey* privateKey, const ByteString& encryptedData, ByteString& data, const AsymMech::Type padding)
{
    return false;
}

unsigned long  OSSLMLDSA::getMinKeySize()
{
    return 2560;
}
unsigned long  OSSLMLDSA::getMaxKeySize()
{
    return 4896;
}

bool OSSLMLDSA::  deriveKey(SymmetricKey **ppSymmetricKey, PublicKey* publicKey, PrivateKey* privateKey)
{
    return false;
}
bool OSSLMLDSA::  reconstructKeyPair(AsymmetricKeyPair** ppKeyPair, ByteString& serialisedData)
{
    return false;
}
bool OSSLMLDSA::  reconstructPublicKey(PublicKey** ppPublicKey, ByteString& serialisedData)
{
    return false;
}

bool OSSLMLDSA::  reconstructPrivateKey(PrivateKey** ppPrivateKey, ByteString& serialisedData)
{
    return false;
}
bool OSSLMLDSA::  reconstructParameters(AsymmetricParameters** ppParams, ByteString& serialisedData)
{
    return false;
}

PublicKey*  OSSLMLDSA::newPublicKey()
{
    return NULL;
}

PrivateKey* OSSLMLDSA:: newPrivateKey()
{
    return NULL;
}

AsymmetricParameters* OSSLMLDSA:: newParameters()
{
    return NULL;
}


