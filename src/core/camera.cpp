#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, 3.0f);

    yaw = -90.0f;
    pitch = 0.0f;

    lastX = 400.0f;
    lastY = 300.0f;

    firstMouse = true;

    updateVectors();
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(
        position,
        position + front,
        glm::vec3(0,1,0)
    );
}

void Camera::updateVectors()
{
    front.x = cos(glm::radians(yaw)) *
              cos(glm::radians(pitch));

    front.y = sin(glm::radians(pitch));

    front.z = sin(glm::radians(yaw)) *
              cos(glm::radians(pitch));

    front = glm::normalize(front);

    up = glm::vec3(0.0f, 1.0f, 0.0f);

    right = glm::normalize(
        glm::cross(front, up)
    );
}

void Camera::processMouse(float xpos, float ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;


    // TODO: poner en un archivo de configuracion.
    float sensitivity = 0.1f;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;

    if (pitch < -89.0f)
        pitch = -89.0f;

    //std::cout << pitch << std::endl;

    updateVectors();
}


void Camera::processKeyboard(GLFWwindow* window, float deltaTime)
{
    float velocity = movementSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        position += front * velocity;
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        position -= front * velocity;
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        position -= right * velocity;
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        position += right * velocity;
    }

}