
#include "core/window.h"
#include "renderer/renderer.h"
#include "renderer/shader.h"
#include "renderer/primitives/vertex_array.h"
#include "renderer/primitives/vertex_buffer.h"
#include "renderer/primitives/index_buffer.h"
#include "core/core.h"

int main() {

    Window window;
    Renderer renderer;

    float positions[] = {
            -0.5f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f
    };

    unsigned int indices[] = {
            0, 1, 3,
            3, 1, 2
    };

    ShaderProgram program("../src/res/default.glsl");

    VertexArray va;
    VertexBuffer vb(positions, 4 * 3 * sizeof(float));

    VertexBufferLayout layout;
    layout.addAttribute<float>(3);

    va.addBuffer(vb, layout);
    IndexBuffer ib(indices, 6);

    while (!window.shouldClose()) {

        renderer.prepare();
        renderer.render(va, ib, program);
        window.update();
    }
    window.destroy();
}
