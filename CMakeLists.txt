cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game
    src/main.cpp
    src/window.cpp
    src/shader.cpp
    src/mesh.cpp
    src/camera.cpp
    external/glad/src/glad.c
)

target_include_directories(game PRIVATE
    external/glad/include
)

find_package(glfw3 REQUIRED)

target_link_libraries(game
    PRIVATE glfw
    PRIVATE GL
)