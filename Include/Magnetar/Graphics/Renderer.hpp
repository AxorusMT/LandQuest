#pragma once
#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol/sokol_gfx.h"
#include "SDL2/SDL.h"

#include "Magnetar/Core/Core.hpp"
#include "Magnetar/Core/Logger.hpp"
#include "Magnetar/Graphics/Window.hpp"


namespace Magnetar {
    namespace Graphics {
        class Renderer {
            public:
                Renderer(Magnetar::Logger* logger, Window* window);
                Renderer() = default;
                ~Renderer();

                void run();
            private:
                Magnetar::Logger* logger = nullptr;
                Window* window = nullptr;

                sg_desc description = {0};

                sg_buffer_desc bufferDescription = {0};
                sg_buffer buffer = {0};

                sg_shader_desc shaderDescription {0};
                sg_shader shader = {0};

                sg_pipeline_desc pipelineDescription {0};
                sg_pipeline pipeline = {0};

                sg_bindings bindings = {0};
                sg_pass_action passAction = {0};
        };
    }
}
