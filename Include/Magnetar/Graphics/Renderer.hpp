#pragma once

#include "Magnetar/Core/Core.hpp"
#include "Magnetar/Core/Logger.hpp"
#include "Magnetar/Graphics/Window.hpp"

#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol/sokol_gfx.h"
#include "SDL2/SDL.h"

namespace Magnetar {
    namespace Graphics {
        class Renderer {
            public:
                Renderer(Magnetar::Logger* logger, Window* window);
                ~Renderer();
            private:
                std::shared_ptr<Magnetar::Logger> logger = nullptr;
                std::shared_ptr<Window> window = nullptr;
        };
    }
}
