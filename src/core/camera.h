#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

class Camera
{
    
private:
    float movementSpeed = 5.0f;

public:
    //yaw y pitch = entrada del jugador
    //front = dirección calculada
    //view matrix = cámara final
    //shader = usa la view matrix
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

    void processKeyboard(GLFWwindow* window, float deltaTime);

};