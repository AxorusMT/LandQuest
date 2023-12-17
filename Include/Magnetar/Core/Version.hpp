#pragma once
#include "Core.hpp"

namespace Magnetar {
    /**
     * @brief Get the version of the Magnetar Game Engine
     * @since 0.0.1
     * 
     */
    class Version {
        public:
            /**
             * @brief Get the Major version of Magnetar. This is the first number in semantic versioning
             * 
             * @return uint8 
             */
            static uint8 getMajor();

            /**
             * @brief Get the Minor version of Magnetar. This is the second number in semantic versioning
             * 
             * @return uint8 
             */
            static uint8 getMinor();

            /**
             * @brief Get the Patch version of Magnetar. This is the third number of semantic versioning
             * 
             * @return uint8 
             */
            static uint8 getPatch();

            /**
             * @brief Get the Letter version of Magnetar. This is optional, used to represent really small chanages
             * 
             * @return char 
             */
            static char getLetter();

            /**
             * @brief Get a formatted string of the Magnetar version in the form "major.minor.patchletter"
             * 
             * @return std::string 
             */
            static std::string getString();
    };
}