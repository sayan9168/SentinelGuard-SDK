#include "AA_Network.h"
#include <iostream>

namespace SentinelGuard {
    NetworkController::NetworkController(std::string deviceID) : id(deviceID) {}

    bool NetworkController::syncDeviceStatus() {
        // Future-e ekhane actual HTTP request hobe
        // Jodi server response "DEACTIVATE" hoy, tobe return hobe false
        
        bool isContractActive = true; // API call output mockup
        
        if (!isContractActive) {
            std::cout << "ALERT: Service Terminated by Provider. Locking Hardware." << std::endl;
            return false; 
        }
        return true;
    }
}
