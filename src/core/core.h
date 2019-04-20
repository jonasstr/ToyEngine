#pragma once

#include <csignal>

#include <glad/glad.h>
#include <iostream>

#define ASSERT(x) if (!(x)) raise(SIGTRAP)

#define GL_CALL(x) clearErrors();\
    x;\
    ASSERT(printError(__BASE_FILE__, __LINE__, #x))

static void clearErrors() {
    while (glGetError() != GL_NO_ERROR);
}

static bool printError(const char *file, unsigned int line, const char *function) {
    if (GLenum error = glGetError()) {
        std::cout << error;
        std::cerr << "GL_ERROR in " << file << " : " << line << " - " << function << std::endl;
        return false;
    }
    return true;
}
