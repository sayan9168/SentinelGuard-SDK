#include "SentinelCore.h"
#include <iostream>

namespace SentinelGuard {

    bool SentinelCore::verifyUser(std::string digitalSignature) {
        // Future-e ekhane RSA/ECC Algorithm thakbe
        // Signature valid hole trigger enable hobe
        if (digitalSignature == "VALID_CRYPTO_TOKEN") {
            this->currentStatus = AUTHORIZED;
            return true;
        } else {
            this->currentStatus = LOCKED;
            return false;
        }
    }

    bool SentinelCore::verifyHardwareIntegrity() {
        // Hardware-er casing khola hoyeche kina check korbe
        bool isTampered = false; // Sensor theke asbe
        return !isTampered;
    }
}
