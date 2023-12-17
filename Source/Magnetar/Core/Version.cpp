#include "Magnetar/Core/Version.hpp"

uint8 Magnetar::Version::getMajor() {
    #ifdef MAGNETAR_VERSION_MAJOR
        return MAGNETAR_VERSION_MAJOR;
    #else   
        return 0;
    #endif
}

uint8 Magnetar::Version::getMinor() {
    #ifdef MAGNETAR_VERSION_MINOR
        return MAGNETAR_VERSION_MINOR;
    #else   
        return 0;
    #endif
}

uint8 Magnetar::Version::getPatch() {
    #ifdef MAGNETAR_VERSION_PATCH
        return MAGNETAR_VERSION_PATCH;
    #else   
        return 0;
    #endif
}

char Magnetar::Version::getLetter() {
    #ifdef MAGNETAR_VERSION_LETTER
        return MAGNETAR_VERSION_LETTER;
    #else   
        return '!';
    #endif
}

std::string Magnetar::Version::getString() {
    return std::format("{}.{}.{}{}",
        getMajor(),
        getMinor(),
        getPatch(),
        getLetter()
    );
}