#include "shader.h"

void Shader::compile(const char* vs, const char* fs) 
{
    unsigned int v = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v, 1, &vs, nullptr);
    glCompileShader(v);

    unsigned int f = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f, 1, &fs, nullptr);
    glCompileShader(f);

    id = glCreateProgram();
    glAttachShader(id, v);
    glAttachShader(id, f);
    glLinkProgram(id);

    glDeleteShader(v);
    glDeleteShader(f);
}

void Shader::use() const 
{
    glUseProgram(id);
}

void Shader::setMat4(const char* name, glm::mat4 m) const 
{
    glUniformMatrix4fv(
        glGetUniformLocation(id, name),
        1, GL_FALSE,
        glm::value_ptr(m)
    );
}