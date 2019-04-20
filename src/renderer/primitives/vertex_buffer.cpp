
#include "vertex_buffer.h"

#include <glad/glad.h>

#include "core/core.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    GL_CALL(glGenBuffers(1, &id));
    bind();
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GL_CALL(glDeleteBuffers(1, &id));
}

void VertexBuffer::bind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void VertexBuffer::unbind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
