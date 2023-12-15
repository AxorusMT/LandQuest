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
            static inline constexpr PlatformType getPlatformType();
            static inline constexpr std::string getPlatformString();
    };      
}