
#include <renderer/texture.h>
#include <renderer/primitives/vertex_buffer.h>
#include <renderer/primitives/vertex_array.h>
#include <renderer/primitives/index_buffer.h>
#include "raw_model.h"

RawModel::RawModel(const void *positions, const unsigned int *indices) {

    va = new VertexArray();
    va->bind();
    vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.addAttribute<float>(2);
    layout.addAttribute<float>(2);

    va->addBuffer(*vb, layout);
    ib = new IndexBuffer(indices, 6);
}

RawModel::~RawModel() {
    delete va;
    delete vb;
    delete ib;
}

void RawModel::bindAll() const {
    va->bind();
    ib->bind();
}

unsigned int RawModel::getVertexCount() const {
    return 6;
}
