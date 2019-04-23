#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <models/raw_model.h>
#include "renderer/primitives/vertex_array.h"
#include "shader.h"
#include "renderer/primitives/index_buffer.h"

class Renderer {

public:

    void prepare() const;

    void render(const RawModel& model, const ShaderProgram& program) const;
};
