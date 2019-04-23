
#include "vertex_array.h"

#include <glad/glad.h>

#include "core/core.h"

VertexArray::VertexArray() {
    GL_CALL(glGenVertexArrays(1, &id));
    bind();
}

VertexArray::~VertexArray() {
    GL_CALL(glDeleteVertexArrays(1, &id));
}

void VertexArray::bind() const {
    GL_CALL(glBindVertexArray(id));
}

void VertexArray::unbind() const {
    GL_CALL(glBindVertexArray(0));
}

void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) const {

    bind();
    buffer.bind();
    const auto &attributes = layout.getAttributes();
    unsigned int offset = 0;

    int boundBuffer;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &boundBuffer);

    for (unsigned int i = 0; i < attributes.size(); i++) {

        const auto &attribute = attributes[i];
        // size_t to avoid conversion warning from unsigned int to const void*
        GL_CALL(glVertexAttribPointer(i, attribute.count, attribute.type, attribute.normalized, layout.getStride(),
                                      (const void *) (size_t) offset));
        GL_CALL(glEnableVertexAttribArray(i));
        offset += attribute.count * VertexBufferAttribute::getSizeOfType(attribute.type);
    }
}
