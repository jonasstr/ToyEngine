
#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

#include <glad/glad.h>

#include <core/core.h>

class Shader {
private:
    unsigned int type;
    std::string source;

public:
    // Constructs a new shader with the given type and source code.
    Shader(unsigned int type, std::string &source);

    // Compiles this shader and returns its ID.
    unsigned int compile();

private:
    // Utility function for checking shader compilation/linking errors.
    static void checkCompileErrors(unsigned int id);
};

class ShaderProgram {
private:
    // The ID of this shader program.
    unsigned int id;
    // The vertex and fragment shader code.
    std::string vertexSource, fragmentSource;

    std::unordered_map<std::string, int> uniformLocationCache;

    void createProgram();

    int getUniformLocation(const std::string &name);

public:
    // Reads the shaders from the file path and set the shader sources.
    ShaderProgram(const std::string &filePath);

    void bind() const;

    // Utility uniform functions.
    void setUniform4f(const std::string &name, float v1, float v2, float v3, float v4);

    inline unsigned int getId() const { return id; }
};
