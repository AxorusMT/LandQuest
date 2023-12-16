#include "Magnetar/Core/Logger.hpp"
#include "Magnetar/Core/Platform.hpp"

int main() {
    Magnetar::Logger logger(true); 
    
    logger.fatal("The quick brown fox jumps over the lazy dog!");
    return 0;
}