#include "Magnetar/Graphics/Renderer.hpp"

Magnetar::Graphics::Renderer::Renderer(Magnetar::Logger* logger, Window* window) {
    this->logger = logger;
    this->window = window;

    
    sg_setup(description);

    const float vertices[] = {
        // positions            // colors
         0.0f,  0.5f, 0.5f,     1.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.5f,     0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, 1.0f, 1.0f
    };

    
    bufferDescription.data = SG_RANGE(vertices);

    buffer = sg_make_buffer(bufferDescription);
    
    shaderDescription.vs.source =
            "#version 330\n"
            "layout(location=0) in vec4 position;\n"
            "layout(location=1) in vec4 color0;\n"
            "out vec4 color;\n"
            "void main() {\n"
            "  gl_Position = position;\n"
            "  color = color0;\n"
            "}\n";
    
    shaderDescription.fs.source =
            "#version 330\n"
            "in vec4 color;\n"
            "out vec4 frag_color;\n"
            "void main() {\n"
            "  frag_color = color;\n"
            "}\n";

   
    
    pipelineDescription.shader = shader;
    pipelineDescription.layout.attrs[0].format = SG_VERTEXFORMAT_FLOAT3;
    pipelineDescription.layout.attrs[1].format = SG_VERTEXFORMAT_FLOAT4;

    bindings.vertex_buffers[0] = buffer;

    
}

Magnetar::Graphics::Renderer::~Renderer() {
    sg_shutdown();
}

void Magnetar::Graphics::Renderer::run() {
    int current_width, current_height;
    SDL_GetWindowSize(this->window->getUnderlyingWindow(), &current_width, &current_height);
    sg_begin_default_pass(&passAction, current_width, current_height);
    sg_apply_pipeline(pipeline);
    sg_apply_bindings(&bindings);
    sg_draw(0, 3, 1);
    sg_end_pass();
    sg_commit();
    SDL_GL_SwapWindow(window->getUnderlyingWindow());
}