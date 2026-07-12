#include "window.h"

bool Window::init(int w, int h, const char* title) 
{
    #ifdef __linux__
        std::cout << "Starting engine in Linux...\n";
        glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
        std::cout << "Wayland is not compatible for GLFW yet, using X11 platform....\n";
    #elif defined(_WIN32)
        std::cout << "Starting Engine in windows...\n";
    #elif defined(__APPLE__)
        std::cout << "Starting engine in MacOS...\n";
    #else
        std::cout << "Sistema operativo no reconocido. Cerrando programa.";
        return false;
    #endif

    // ERROR CALLBACK
    glfwSetErrorCallback(
    [](int error, const char* description)
        {
            std::cout << "GLFW Error " << error
                    << ": " << description
                    << "\n";
        }
    );

    if (!glfwInit()) return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    handle = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if (!handle) return false;

    glfwMakeContextCurrent(handle);

    return true;
}

GLFWwindow* Window::getHandle() const
{
    return handle;
}

bool Window::shouldClose() const 
{
    return glfwWindowShouldClose(handle);
}

void Window::close() const 
{
    glfwSetWindowShouldClose(handle, true);
}

void Window::poll() const
{ 
    glfwPollEvents();
}

void Window::swap() const
{
    glfwSwapBuffers(handle);
}

Window::~Window() 
{
    glfwTerminate();
}