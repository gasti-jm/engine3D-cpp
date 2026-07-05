#pragma once

#include <cstddef>
#include <glad/glad.h>

class Mesh
{
private:
    GLuint VAO, VBO;

public:
    void create(float* vertices, size_t size);
    void draw() const;
};