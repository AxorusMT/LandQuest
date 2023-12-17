#pragma once
#include "Core.hpp"

namespace Magnetar {
    class Version {
        public:
            static uint8 getMajor();
            static uint8 getMinor();
            static uint8 getPatch();
            static char getLetter();

            static std::string getString();
    };
}