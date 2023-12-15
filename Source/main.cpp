#include "Magnetar/Core/Logger.hpp"
#include "Magnetar/Core/Platform.hpp"

int main() {
    Magnetar::Logger logger(true); 

    logger.info(Magnetar::Platform::getPlatformString());
    return 0;
}