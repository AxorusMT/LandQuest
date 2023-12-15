#include "Magnetar/Core/Platform.hpp"

#include "SDL2/SDL.h"


constexpr Magnetar::PlatformType Magnetar::Platform::getPlatformType() {
    #ifdef __MACOSX__
        return PlatformType::MacOS;
    #elif  __IPHONEOS__ 
        return PlatformType::iOS;
    #elif __WIN32__ 
        return PlatformType::Windows;
    #elif __LINUX__
        return PlatformType::Linux;
    #elif __ANDROID__
        return PlatformType::Android;
    #else 
        return PlatformType::Unknown;
    #endif
}

constexpr std::string Magnetar::Platform::getPlatformString() {
    switch (getPlatformType()) {
        case PlatformType::Windows:
            return "Windows";
            break; // unnecessary, but just to be sure
        case PlatformType::MacOS:
            return "MacOS";
            break;
        case PlatformType::Linux:
            return "Linux";
            break;
        case PlatformType::iOS:
            return "iOS";
            break;
        case PlatformType::Android:
            return "Android";
            break;
        default:
            return "Unknown";
    }
}