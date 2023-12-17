#pragma once

#include "Magnetar/Core/Core.hpp"
#include "SDL2/SDL.h"

namespace Magnetar {
    /// @brief Namespace for all graphical components (Window, Camera, Renderer, Shaders) etc.
    namespace Graphics {
        /// @brief Holds information about a window, like its width, height, fullscreen etc.

        struct WindowProperties {
            /** @brief The width of the window, not including window decoration like borders and titles 
             *  @since 0.0.1
            */
            uint32 width = 640;

            /** @brief The height of the window, not including window decorations like borders and titles. 
             *  @since 0.0.1
            */
            uint32 height = 480;

            /**
             * @brief The x position of the window when it is created. Note that +x is going *right* on the monitor.
             * @since 0.0.1
             */
            uint16 x = 0;

            /**
             * @brief The y position of the window when it is created. Note that +y is going *down* on the monitor
             * @since 0.0.1
             * 
             */
            uint16 y = 0;
            
            /**
             * @brief Controls whether or not the window is centered on the X axis.
             * @since 0.0.1
             * 
             */
            bool center_x = true;

            /**
             * @brief Controls whether or not the window is centered on the Y axis.
             * @since 0.0.1
             */
            bool center_y = true;

            /**
             * @brief The title of the window that is shown when it is created.
             * @since 0.0.1
             * 
             */
            std::string title = "MagnetarWindow";

            /**
             * @brief Controls whether the window starts fullscreen or not. Note that this controls whether the window is fullscreen compared to the
             * desktop, which avoids stretching. This is equivalent to `SDL_WINDOW_FULLSCREEN_DESKTOP`, not `SDL_WINDOW_FULLSCREEN`.
             * @since 0.0.1
             */
            bool fullscreen = false;

            /**
             * @brief Controls whether or not the window is resizable, i.e. its size can be changed
             * @since 0.0.1
             */
            bool resizable = true;

            /**
             * @brief Controls whether or not the window starts out maximized or not. Note that this differs from \ref fullscreen
             * as with maximized, the window still has its decoration, like window titles and borders
             * @since 0.0.1
             */
            bool maximized = false;

            /**
             * @brief Controls whether or not the window is borderless; i.e. It has its decoration
             * @since 0.0.1
             */
            bool borderless = false;
        };


        class Window {
            public:
                Window(const WindowProperties& properties);
                ~Window();

                /**
                 * @brief Get the current window properties being used.
                 * @since 0.0.1
                 * @return WindowProperties 
                 * 
                 * An example:
                 * @code{.cpp}
                 *      WindowProperties properties;
                 *      properties.width = 1280;
                 *      properties.height = 720;
                 *      properties.fullscreen = true;
                 * 
                 *      Window window(properties);
                 * 
                 *      // Turn off fullscreen
                 * 
                 *      WindowProperties props = window.getProperties();
                 *      props.fullscreen = false;
                 *      window.setProperties(props);
                 * @endcode
                 */
                WindowProperties getProperties();
                void setProperties(WindowProperties& props);
                //temp

                SDL_Window* getUnderlyingWindow();
            private:
                WindowProperties properties;
                SDL_Window* window = nullptr;

                // temp 
                bool isRun = true;
        };
    }
}