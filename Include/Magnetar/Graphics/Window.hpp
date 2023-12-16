#pragma once

#include "Magnetar/Core/Core.hpp"
#include "SDL2/SDL.h"

namespace Magnetar {
    namespace Graphics {
        struct WindowProperties {
            uint32 width = 640;
            uint32 height = 480;
            uint16 x = 0;
            uint16 y = 0;
            std::string title = "Magnetar Window";

            bool fullscreen = false;
            bool resizable = true;
            bool maximized = false;
            bool center_x = true;
            bool center_y = true;
            bool borderless = false;
        };


        class Window {
            public:
                Window(const WindowProperties& properties);
                ~Window();

                WindowProperties getProperties();

                //temp

                void run();
            private:
                WindowProperties properties;
                SDL_Window* window = nullptr;

                // temp 
                bool isRun = true;
        };
    }
}