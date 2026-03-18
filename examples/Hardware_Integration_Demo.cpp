#include <iostream>
#include "SentinelCore.h"
#include "AA_Network.h"
#include "AA_BlackBox.h"

using namespace SentinelGuard;

int main() {
    // 1. Initializing System Components
    SentinelCore core;
    NetworkController network("SG-9168-X");
    BlackBox logger;

    std::cout << "--- SentinelGuard System Booting ---" << std::endl;

    // 2. Network Check (Kill-Switch / Contract Status)
    if (!network.syncDeviceStatus()) {
        std::cout << "[CRITICAL] Service Terminated. Hardware Locked." << std::endl;
        logger.recordEvent("REMOTE_LOCK_ACTIVATED", false);
        return 0; // System stops here
    }

    // 3. Location Check (Geofencing)
    // Example: User is near a School (Restricted Zone)
    core.updateLocation(22.5726, 88.3639); 
    
    if (core.getSystemStatus() == GEO_RESTRICTED) {
        std::cout << "[WARNING] Restricted Zone Detected. Trigger Disabled." << std::endl;
        logger.recordEvent("GEO_BLOCK_ALARM", false);
    } else {
        // 4. User Authentication (Biometric/Digital Signature)
        std::string userToken = "VALID_CRYPTO_TOKEN"; // Simulated from Sensor
        
        if (core.verifyUser(userToken)) {
            std::cout << "[SUCCESS] User Authorized. System Ready." << std::endl;
            logger.recordEvent("USER_LOGIN_SUCCESS", true);
            
            // Physical Hardware Trigger Enable Logic ekhane hobe
        } else {
            std::cout << "[ERROR] Unauthorized Access Attempt!" << std::endl;
            logger.recordEvent("UNAUTHORIZED_ACCESS", false);
        }
    }

    return 0;
}
