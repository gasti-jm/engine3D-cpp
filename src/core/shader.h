#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class Shader
{
private:
    unsigned int id;

public:
    void compile(const char* vs, const char* fs);
    void use() const;
    void setMat4(const char* name, glm::mat4 m) const;
};