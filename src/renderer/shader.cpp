#include "shader.h"

Shader::Shader(unsigned int type, std::string &source) : type{type}, source{source} {}

unsigned int Shader::compile() {
    GL_CALL(unsigned int id = glCreateShader(type));
    const char *src = source.c_str();
    GL_CALL(glShaderSource(id, 1, &src, nullptr));
    GL_CALL(glCompileShader(id));
    checkCompileErrors(id);
    return id;
}

void Shader::checkCompileErrors(unsigned int id) {
    int success;
    char infoLog[1024];
    GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &success));
    if (!success) {
        GL_CALL(glGetShaderInfoLog(id, 1024, nullptr, infoLog));
        std::cerr << "ERROR::SHADER_COMPILATION: " << "\n" << infoLog
                  << "-----------------------------------------------" << std::endl;
    }
}

// Read the shaders from the file path and set the shader sources.
    ShaderProgram::ShaderProgram(
    const std::string &filePath) {
        std::ifstream stream(filePath);
        if (stream.fail()) {
            std::cerr << "ERROR::SHADER_PROGRAM: Could not find shader " << filePath << "!" << std::endl;
        }

        enum class ShaderType {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };
        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        // Put current line of stream into line.
        while (getline(stream, line)) {
            // Search within line string.
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) {
                    type = ShaderType::VERTEX;
                } else if (line.find("fragment") != std::string::npos) {
                    type = ShaderType::FRAGMENT;
                }
                // ShaderParser specific code found.
            } else {
                ss[(int) type] << line << '\n';
            }
        }
        vertexSource = ss[(int) ShaderType::VERTEX].str();
        fragmentSource = ss[(int) ShaderType::FRAGMENT].str();
        createProgram();
    }

    void ShaderProgram::createProgram() {

        GL_CALL(id = glCreateProgram());
        unsigned int vs = Shader(GL_VERTEX_SHADER, vertexSource).compile();
        unsigned int fs = Shader(GL_FRAGMENT_SHADER, fragmentSource).compile();

        GL_CALL(glAttachShader(id, vs));
        GL_CALL(glAttachShader(id, fs));
        GL_CALL(glLinkProgram(id));
        GL_CALL(glValidateProgram(id));

        GL_CALL(glDeleteShader(vs));
        GL_CALL(glDeleteShader(fs));
    }

    void ShaderProgram::bind() const {
        GL_CALL(glUseProgram(id));
    }

    void ShaderProgram::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
        GL_CALL(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
    }

    int ShaderProgram::getUniformLocation(const std::string &name) {

        if (uniformLocationCache.find(name) != uniformLocationCache.end()) {
            return uniformLocationCache[name];
        }
        GL_CALL(int location = glGetUniformLocation(id, name.c_str()));
        if (location == -1) {
            std::cout << "WARNING: shader uniform " << name << " doesn't exist!" << std::endl;
        }
        uniformLocationCache[name] = location;
        return location;
    }