#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {

public:

    GLFWwindow *window;

    Window();

    void update() const;

    void destroy() const;

    bool shouldClose() const;

private:

    static void frameBufferCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
};
