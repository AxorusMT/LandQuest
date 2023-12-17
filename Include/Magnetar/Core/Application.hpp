#pragma once

#include "Core.hpp"
#include "Logger.hpp"
#include "Platform.hpp"

#include "Magnetar/Graphics/Window.hpp"
#include "Magnetar/Graphics/Renderer.hpp"

namespace Magnetar {
    /**
     * @brief A Magnetar Application
     * @since 0.0.1
     */
    class Application {
        public:
            Application(uint16 width, uint16 height, std::string title, bool logToFile = true);
            Application(Graphics::WindowProperties& props, bool logToFile = true);


            void run();
            ~Application();

            // TODO: Add getters and setters
        private:

            void setup();
            bool isRun = true;
            std::string name = "MagnetarApplication";
            // TODO:  add versioning
            std::unique_ptr<Graphics::Window> window = nullptr;
            std::unique_ptr<Logger> logger;

            Graphics::WindowProperties properties;
            Graphics::Renderer renderer; // make this a POINTER later.

    };
}
