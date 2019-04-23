
#include "renderer.h"
#include "renderer/primitives/vertex_array.h"
#include "core/core.h"
#include "shader.h"
#include "renderer/primitives/index_buffer.h"

void Renderer::prepare() const {
    GL_CALL(glClearColor(0, 0, 1, 1));
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::render(const RawModel& model, const ShaderProgram& program) const {
    model.bindAll();
    program.bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, nullptr));
}
