cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(game
    ${SOURCES}
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