#include "Magnetar/Core/Logger.hpp"

int main() {
    Magnetar::Logger logger(true); 

    logger.blockLogLevels({Magnetar::LogLevel::Warn});
    logger.info("Hello world info!");
    logger.debug("Hello world debug!");
    logger.warn("Hello world warn!");
    logger.error("Hello world error!");
    logger.fatal("Hello world fatal!");
    return 0;
}