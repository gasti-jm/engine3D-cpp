/*************************************************
 * Jorge Gaston Martinez - 3D Engine
 * main.cpp - here start own game :D
 * COPYRIGHT 2026
 *************************************************/

#include "core/window.h"
#include "core/shader.h"
#include "core/mesh.h"
#include "core/camera.h"
#include "core/timer.h"
#include "core/mesh_factory.h"

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

int main() 
{
    Timer timer;
    Window window;
    Camera camera;

    if (!window.init(800, 600, "Engine")) return -1;

    glfwSetInputMode(
        window.getHandle(),
        GLFW_CURSOR,
        GLFW_CURSOR_DISABLED
    );

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glEnable(GL_DEPTH_TEST); // depth buffer (permite el dibujado segun distancias. )

    Shader shader;
    shader.compile(vertexShaderSrc, fragmentShaderSrc);

    Mesh quad = MeshFactory::createQuad();

    //Mesh mesh;
    //mesh.create(vertices, sizeof(vertices), indices, sizeof(indices));

    while (!window.shouldClose()) 
    {
        timer.update();
        float dt = timer.getDeltaTime();
        //std::cout << timer.getDeltaTime() << '\n';
        float speed = 0.05f;

        camera.processKeyboard(window.getHandle(), timer.getDeltaTime());

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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

        quad.draw();

        window.swap();
        window.poll();
    }
}