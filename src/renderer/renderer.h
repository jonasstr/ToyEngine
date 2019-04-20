#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renderer/primitives/vertex_array.h"
#include "shader.h"
#include "renderer/primitives/index_buffer.h"

class Renderer {

public:

    void prepare() const;

    void render(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& program) const;
};
