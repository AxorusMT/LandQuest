#include "Magnetar/Graphics/Window.hpp"
#include "Magnetar/Core/Logger.hpp"

Magnetar::Graphics::Window::Window(const Magnetar::Graphics::WindowProperties& properties) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << SDL_GetError() << std::endl;
        std::exit(EXIT_FAILURE);
    }   
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    this->properties = properties;

    uint32 windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
    uint16 x = this->properties.center_x ? SDL_WINDOWPOS_CENTERED : this->properties.x;
    uint16 y = this->properties.center_y ? SDL_WINDOWPOS_CENTERED : this->properties.y;

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

    if (window == nullptr) {
        std::exit(EXIT_FAILURE);
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);

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
    WindowProperties oldProps = this->properties;
    this->properties = props;

    if ((oldProps.width != props.width) || (oldProps.height != props.height)) {
        SDL_SetWindowSize(window, props.width, props.height);
    }

    if ((oldProps.x != props.x) || (oldProps.y != props.y) || (oldProps.center_x != props.center_x) || (oldProps.center_y != props.center_y)) {    
        uint16 x = this->properties.center_x ? SDL_WINDOWPOS_CENTERED : this->properties.x;
        uint16 y = this->properties.center_y ? SDL_WINDOWPOS_CENTERED : this->properties.y;
        SDL_SetWindowPosition(window, x, y);
    }

    if (oldProps.title != props.title) {
        SDL_SetWindowTitle(window, props.title.c_str());
    }

    if (oldProps.fullscreen != props.fullscreen) {
        uint32 fullscreen = props.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
        SDL_SetWindowFullscreen(window, fullscreen);
    }

    if (oldProps.resizable != props.resizable) {
        SDL_SetWindowResizable(window, static_cast<SDL_bool>(props.resizable));
    }

    if (oldProps.borderless != props.borderless) {
        SDL_SetWindowBordered(window, static_cast<SDL_bool>(props.borderless));
    }

}

SDL_Window* Magnetar::Graphics::Window::getUnderlyingWindow() {
    return this->window;
}

