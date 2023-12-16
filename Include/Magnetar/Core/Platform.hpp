#pragma once

#include <string>

namespace Magnetar {
    enum class PlatformType {
        Unknown,
        Windows,
        Linux,
        MacOS,
        iOS,
        Android
    };

    class Platform {
        public:
            static PlatformType getPlatformType();
            static std::string getPlatformString();
    };      
}