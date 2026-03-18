#ifndef SENTINEL_CORE_H
#define SENTINEL_CORE_H

#include <string>
#include <vector>

namespace SentinelGuard {

    enum SystemStatus {
        LOCKED,
        AUTHORIZED,
        EMERGENCY_BLOCK,
        GEO_RESTRICTED
    };

    class SentinelCore {
    public:
        SentinelCore();
        
        // --- Authentication ---
        bool initializeAuth(std::string publicKey); 
        bool verifyUser(std::string digitalSignature);

        // --- Safety Controls ---
        void updateLocation(double lat, double lon);
        bool isActionPermitted();

        // --- System Commands ---
        void triggerRemoteLock();
        SystemStatus getSystemStatus();

    private:
        SystemStatus currentStatus;
        std::string deviceID;
        bool checkGeofence(double lat, double lon);
        bool verifyHardwareIntegrity();
    };

}

#endif
