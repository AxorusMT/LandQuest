#include "Magnetar/Graphics/Renderer.hpp"

Magnetar::Graphics::Renderer::Renderer(Magnetar::Logger* logger, Window* window) {
    sg_desc desc = {0};
    sg_setup(desc);

    const float vertices[] = {
        // positions            // colors
         0.0f,  0.5f, 0.5f,     1.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.5f,     0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, 1.0f, 1.0f
    };

    sg_buffer_desc buffer_desc;
    buffer_desc.data = SG_RANGE(vertices);

    sg_buffer buffer = {0};
    buffer = sg_make_buffer(buffer_desc);
    
}