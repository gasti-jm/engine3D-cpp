#include "timer.h"

void Timer::update()
{
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
}

float Timer::getDeltaTime() const
{
    return deltaTime;
}

float Timer::getTime() const
{
    return currentTime;
}