#include "window.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const char* vertexShaderSrc = R"(
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 vColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vColor = aColor;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

const char* fragmentShaderSrc = R"(
#version 330 core

in vec3 vColor;
in vec2 vUV;

out vec4 FragColor;

void main() {
    FragColor = vec4(vColor, 1.0);
}
)";

int main() {
    Window window;
    Camera camera;

    if (!window.init(800, 600, "Engine")) return -1;

    glfwSetInputMode(
        window.getHandle(),
        GLFW_CURSOR,
        GLFW_CURSOR_DISABLED
    );

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Shader shader;
    shader.compile(vertexShaderSrc, fragmentShaderSrc);

    float vertices[] = {
        0.0,  0.5, 0.0,  1,0,0, 0.5,1,
       -0.5, -0.5, 0.0,  0,1,0, 0,0,
        0.5, -0.5, 0.0,  0,0,1, 1,0
    };

    Mesh mesh;
    mesh.create(vertices, sizeof(vertices));

    while (!window.shouldClose()) {
        float speed = 0.01f;

        if (glfwGetKey(window.getHandle(), GLFW_KEY_W) == GLFW_PRESS)
        {
            camera.position += camera.front * speed;
        }

        if (glfwGetKey(window.getHandle(), GLFW_KEY_S) == GLFW_PRESS)
        {
            camera.position -= camera.front * speed;
        }

        if (glfwGetKey(window.getHandle(), GLFW_KEY_A) == GLFW_PRESS)
        {
            camera.position -= camera.right * speed;
        }

        if (glfwGetKey(window.getHandle(), GLFW_KEY_D) == GLFW_PRESS)
        {
            camera.position += camera.right * speed;
        }

        if (glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        {
            window.close();
        }

        double mouseX;
        double mouseY;

        glfwGetCursorPos(
            window.getHandle(),
            &mouseX,
            &mouseY
        );

        camera.processMouse(
            (float)mouseX,
            (float)mouseY
        );

        glClearColor(0.1,0.1,0.1,1);
        glClear(GL_COLOR_BUFFER_BIT);

        float time = glfwGetTime();

        glm::mat4 model = glm::rotate(
            glm::mat4(1.0f),
            time,
            glm::vec3(0,0,1)
        );

        glm::mat4 view = camera.getViewMatrix();

        glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            800.0f/600.0f,
            0.1f,
            100.0f
        );

        shader.use();
        shader.setMat4("model", model);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        mesh.draw();

        window.swap();
        window.poll();
    }
}