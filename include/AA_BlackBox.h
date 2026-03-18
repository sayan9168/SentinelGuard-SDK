#ifndef AA_BLACKBOX_H
#define AA_BLACKBOX_H

#include <string>
#include <vector>

namespace SentinelGuard {
    struct EventLog {
        std::string timestamp;
        std::string eventType;
        double latitude;
        double longitude;
        bool isAuthorized;
    };

    class BlackBox {
    public:
        BlackBox();
        // Log-ke encrypt kore store korbe
        void recordEvent(std::string type, bool authStatus);
        
        // Shudhu private key thaklei log read kora jabe
        std::vector<EventLog> exportLogs(std::string adminKey);

    private:
        void encryptData(std::string data);
        std::string storagePath = "/secure/logs.dat";
    };
}

#endif
