#include "Magnetar/Graphics/Window.hpp"
#include "Magnetar/Core/Logger.hpp"

Magnetar::Graphics::Window::Window(const Magnetar::Graphics::WindowProperties& properties) {
    this->properties = properties;

    uint32 windowFlags = SDL_WINDOW_SHOWN;
    uint32 x = this->properties.center_x ? SDL_WINDOWPOS_CENTERED : this->properties.x;
    uint32 y = this->properties.center_y ? SDL_WINDOWPOS_CENTERED : this->properties.y;

    if (this->properties.fullscreen) {
        windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    if (this->properties.resizable) {
        windowFlags |= SDL_WINDOW_RESIZABLE;
    }

    if (this->properties.borderless) {
        windowFlags |= SDL_WINDOW_BORDERLESS;
    }

    if (this->properties.maximized) {
        windowFlags |= SDL_WINDOW_MAXIMIZED;
    }

    window = SDL_CreateWindow(
        this->properties.title.c_str(),
        x,
        y,
        this->properties.width,
        this->properties.height,
        windowFlags
    );

    Magnetar::Logger log(true);

    if (window == nullptr) {
        log.fatal(std::format("Cannot create SDL2 Window, {}", SDL_GetError()));
        std::exit(EXIT_FAILURE);
    }

    log.info("SDL Window successfully created!");
}

Magnetar::Graphics::Window::~Window() {
    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}

Magnetar::Graphics::WindowProperties Magnetar::Graphics::Window::getProperties() {
    return this->properties;
}

void Magnetar::Graphics::Window::setProperties(Magnetar::Graphics::WindowProperties& props) {
    this->properties = props;

    // TODO: Make changing the properties update the window
}
void Magnetar::Graphics::Window::run() {
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
    }
}