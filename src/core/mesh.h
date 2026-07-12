#pragma once

#include <cstddef>
#include <glad/glad.h>

class Mesh
{
private:
    GLuint VAO, VBO, EBO;
    GLuint indexCount;  

public:

    void create(
        float* vertices, size_t size, 
        unsigned int* indices,
        size_t indexSize
    );

    void draw() const;
};