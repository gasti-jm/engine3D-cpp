#pragma once

#include <glm/glm.hpp>
#include <iostream>

class Camera
{
    
public:
    glm::vec3 position;
    glm::vec3 front;

    glm::vec3 right;
    glm::vec3 up;

    float yaw;
    float pitch;

    float lastX;
    float lastY;

    bool firstMouse;

    Camera();

    glm::mat4 getViewMatrix() const;
    void updateVectors();
    void processMouse(float xpos, float ypos);
};