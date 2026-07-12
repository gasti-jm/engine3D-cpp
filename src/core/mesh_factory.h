#pragma once

#include "mesh.h"

// en esta clase vamos a crear Mesh de objeto geometricos para poder hacer pruebas y dibujarlas en pantalla.

class MeshFactory
{
public:
    static Mesh createQuad();
};