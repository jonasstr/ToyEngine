#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "primitives/vertex_array.h"
#include "shader.h"

class Renderer {

public:

    void prepare() const;

    void render(VertexArray& va, ShaderProgram& program) const;
};
