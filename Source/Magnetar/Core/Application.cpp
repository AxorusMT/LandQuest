#include "Magnetar/Core/Application.hpp"
#include "Magnetar/Core/Version.hpp"

Magnetar::Application::Application(uint16 width, uint16 height, std::string name, bool logToFile) {
    this->name = name;
    this->logger = std::make_unique<Logger>(logToFile);

    logger->info("Logger Created");
    logger->info(std::format("Magnetar: Platform: {}", Platform::getPlatformString()));

    this->properties.width = width;
    this->properties.height = height;
    this->properties.center_x = true;
    this->properties.center_y = true;
    this->properties.title = this->name;
    this->properties.fullscreen = false;

    setup();
}

Magnetar::Application::Application(Graphics::WindowProperties& props, bool logToFile) {
    this->properties = props;
    this->name = this->properties.title;
    this->logger = std::make_unique<Logger>(logToFile);

    logger->info("Logger created");
    logger->info(
        std::format("Magnetar v{}, Platform = {}", 
            Version::getString(),
            Platform::getPlatformString()
        )       
    );

    setup();
}

void Magnetar::Application::setup() {
    this->window = std::make_unique<Graphics::Window>(this->properties);
    logger->info("Window Created");

    // temp

    this->window->run();
}

Magnetar::Application::~Application() {
    logger->info("Magnetar Application Destroyed");
}

