
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

    Shader(unsigned int type, std::string &source);
    unsigned int compile();

private:

    static void checkCompileErrors(unsigned int id);
};

class ShaderProgram {

private:

    unsigned int id;
    std::string vertexSource, fragmentSource;
    std::unordered_map<std::string, int> uniformLocationCache;

    void createProgram();

    int getUniformLocation(const std::string &name);

public:
    ShaderProgram(const std::string &filePath);

    void bind() const;
    // Utility uniform functions.
    void setUniform1i(const std::string &name, int v0);
    void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3);

    inline unsigned int getId() const { return id; }
};
