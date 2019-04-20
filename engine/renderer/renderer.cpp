
#include "renderer.h"
#include "primitives/vertex_array.h"
#include "../core.h"
#include "shader.h"
#include "primitives/index_buffer.h"

void Renderer::prepare() const {
    glClearColor(0, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(VertexArray& va, ShaderProgram& program) const {
    va.bind();
    glUseProgram(program.getId());
    GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}