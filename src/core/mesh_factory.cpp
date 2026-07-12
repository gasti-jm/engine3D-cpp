#include "mesh_factory.h"

Mesh MeshFactory::createQuad()
{
    // vertices para un cuadrado
    float vertices[] =
    {
        // posición        color        uv

        // A
        -0.5f,  0.5f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f,

        // B
         0.5f,  0.5f, 0.0f, // pos
        1.0f, 1.0f, 0.0f, // color
        1.0f, 1.0f, // uv


        // C
        -0.5f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f,


        // D
        0.5f, -0.5f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f
    };

    // indices para el EBO.
    unsigned int indices[] =
    {
        0,1,2,
        1,3,2
    };

    Mesh mesh;

    mesh.create(
        vertices,
        sizeof(vertices),
        indices,
        sizeof(indices)
    );


    return mesh;
}