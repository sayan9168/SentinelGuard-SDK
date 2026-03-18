#include "SentinelCore.h"

namespace SentinelGuard {

    bool SentinelCore::checkGeofence(double lat, double lon) {
        // Example: School Area Coordinates
        double restrictedLat = 22.5726; 
        double restrictedLon = 88.3639;

        // Jodi coordinate restricted area-r 500 meter-er moddhe hoy
        if (abs(lat - restrictedLat) < 0.005 && abs(lon - restrictedLon) < 0.005) {
            return true; // Area is restricted
        }
        return false;
    }

    void SentinelCore::updateLocation(double lat, double lon) {
        if (checkGeofence(lat, lon)) {
            this->currentStatus = GEO_RESTRICTED;
        }
    }
}
