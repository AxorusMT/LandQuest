#pragma once

#include "Core.hpp"
#include "Logger.hpp"
#include "Platform.hpp"

#include "Magnetar/Graphics/Window.hpp"

namespace Magnetar {
    class Application {
        public:
            Application(uint16 width, uint16 height, std::string title, bool logToFile = true);
            Application(Graphics::WindowProperties& props, bool logToFile = true);

            ~Application();

            // TODO: Add getters and setters
        private:

            void setup();
            std::string name = "MagnetarApplication";
            // TODO:  add versioning
            std::unique_ptr<Graphics::Window> window = nullptr;
            std::unique_ptr<Logger> logger;

            Graphics::WindowProperties properties;
    };
}
