
#include <renderer/texture.h>
#include <cmath>
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
            -0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 1.0f, 1.0f
    };

    unsigned int indices[] = {
            0, 1, 3,
            3, 1, 2
    };

    ShaderProgram program("../res/default.glsl");
    program.bind();

    //GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    //GL_CALL(glEnable(GL_BLEND));

    VertexArray va;
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.addAttribute<float>(2);
    layout.addAttribute<float>(2);

    va.addBuffer(vb, layout);
    IndexBuffer ib(indices, 6);

    Texture texture("../res/smiley.png");
    texture.bind();

    program.setUniform1i("u_Texture", 0);

    while (!window.shouldClose()) {

        renderer.prepare();
        //program.setUniform4f("u_Color", 1.0f, sin(glfwGetTime()), cos(glfwGetTime()), 1.0f);
        renderer.render(va, ib, program);
        window.update();
    }
    window.destroy();
}
