cmake_minimum_required(VERSION 3.13)
project(Toy)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(Toy
        src/core/glad.c
        src/core/stb_image.cpp
        src/renderer/shader.h
        src/renderer/shader.cpp
        app/application.cpp
        src/core/core.h
        src/core/window.cpp
        src/core/window.h
        src/renderer/renderer.cpp
        src/renderer/renderer.h
        src/renderer/primitives/vertex_array.cpp
        src/renderer/primitives/vertex_array.h
        src/renderer/primitives/vertex_buffer.cpp
        src/renderer/primitives/vertex_buffer.h
        src/renderer/primitives/index_buffer.cpp
        src/renderer/primitives/index_buffer.h
        src/renderer/vertex_buffer_layout.h
        src/renderer/texture.cpp
        src/renderer/texture.h)

set(VENDOR_DIR ${PROJECT_SOURCE_DIR}/vendor)
include_directories(${VENDOR_DIR})
#include_directories("/home/jonas/Dokumente/OpenGL/Redone/res")
target_link_libraries(Toy glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)