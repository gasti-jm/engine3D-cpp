#pragma once
#include <GLFW/glfw3.h>

class Timer
{
public:

    void update();

    float getDeltaTime() const;

    float getTime() const;

private:

    float currentTime = 0.0f;
    float lastTime = 0.0f;
    float deltaTime = 0.0f;
};