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
    #ifdef __MACOSX__
        return "MacOS"
    #elif  __IPHONEOS__ 
        return "iOS";
    #elif __WIN32__ 
        return "Windows";
    #elif __LINUX__
        return "Linux";
    #elif __ANDROID__
        return "Android";
    #else 
        return "Unknown";
    #endif
}