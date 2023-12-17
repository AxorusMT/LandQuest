#include "Magnetar/Core/Application.hpp"
#include "Magnetar/Core/Version.hpp"

Magnetar::Application::Application(uint16 width, uint16 height, std::string title, bool logToFile) {
    this->name = title;
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
    renderer = {this->logger.get(), this->window.get()};
}

Magnetar::Application::~Application() {
    logger->info("Magnetar Application Destroyed");
    SDL_Quit();
}

void Magnetar::Application::run() {
    while (this->isRun) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRun = false;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    isRun = false;
                }
            }
        }

        // Graphics

        this->renderer.run();
    }
}