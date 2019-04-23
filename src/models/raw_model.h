#pragma once
#include "renderer/primitives/vertex_array.h"
#include "renderer/primitives/vertex_buffer.h"
#include "renderer/primitives/index_buffer.h"

class RawModel {

public:

    const VertexArray* va;

    const VertexBuffer* vb;

    const IndexBuffer* ib;

    RawModel(const void* positions, const unsigned int* indices);
    ~RawModel();

    void bindAll() const;

    unsigned int getVertexCount() const;
};
