#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
    GLFWwindow* handle;

public:

    bool init(int w, int h, const char* title);
    bool shouldClose() const;
    void poll() const;
    void swap() const;
    GLFWwindow* getHandle() const;
    void close() const;

    ~Window();
};