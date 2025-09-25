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

OSSLMLDSA::OSSLMLDSA() {
}

bool OSSLMLDSA::generateKeyPair(AsymmetricKeyPair** ppKeyPair, AsymmetricParameters* parameters, RNG* rng)
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

    return false;

}

