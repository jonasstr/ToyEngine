cmake_minimum_required(VERSION 3.13)
project(Redone)

set(CMAKE_CXX_STANDARD 14)

add_executable(Redone engine/glad.c engine/renderer/shader.h engine/renderer/shader.cpp app/application.cpp engine/core.h engine/window.cpp engine/window.h engine/renderer/renderer.cpp engine/renderer/renderer.h engine/renderer/loader.cpp engine/renderer/loader.h engine/renderer/primitives/vertex_array.cpp engine/renderer/primitives/vertex_array.h engine/renderer/primitives/vertex_buffer.cpp engine/renderer/primitives/vertex_buffer.h engine/renderer/primitives/index_buffer.cpp engine/renderer/primitives/index_buffer.h engine/renderer/vertex_buffer_layout.h)

include_directories("/home/jonas/Dokumente/OpenGL/Libraries/Include")
#include_directories("/home/jonas/Dokumente/OpenGL/Redone/res")
target_link_libraries(Redone glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)