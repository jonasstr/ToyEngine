
#include "index_buffer.h"

#include <glad/glad.h>

#include "../../core.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : count(count) {
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));
    GL_CALL(glGenBuffers(1, &id));
    bind();
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GL_CALL(glDeleteBuffers(1, &id));
}

void IndexBuffer::bind() const {
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
}

void IndexBuffer::unbind() const {
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
