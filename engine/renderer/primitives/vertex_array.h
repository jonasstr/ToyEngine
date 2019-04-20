#pragma once

#include "vertex_buffer.h"
#include "../vertex_buffer_layout.h"

class VertexArray {

private:

    unsigned int id;

public:

    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);

    void bind() const;

    void unbind() const;
};
