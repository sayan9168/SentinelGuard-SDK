#ifndef AA_NETWORK_H
#define AA_NETWORK_H

#include <string>

namespace SentinelGuard {
    class NetworkController {
    public:
        NetworkController(std::string deviceID);
        
        // Server theke status check korbe (LOCKED/ACTIVE)
        bool syncDeviceStatus(); 
        
        // Emergency signal pathabe jodi hardware tamper hoy
        void reportTamper(std::string details);

    private:
        std::string id;
        std::string serverEndpoint = "https://api.sentinelguard.io/v1/status/";
    };
}

#endif
