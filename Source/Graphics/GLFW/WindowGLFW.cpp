#include "Graphics/GraphicsDevice.h"
#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

bool WindowSystemInitialize()
{
    return glfwInit();
}

void WindowSystemTerminate()
{
    glfwTerminate();
}

WindowGLFW::WindowGLFW()
{
}

WindowGLFW::WindowGLFW(const WindowGLFW& other)
    : m_Window(other.m_Window)
{
}

WindowGLFW::WindowGLFW(GraphicsDevice* graphicsDevice, const String& title, unsigned int width, unsigned int height, Display* display)
{

}

WindowGLFW::~WindowGLFW()
{
    if (IsOpen())
        Close();
}

bool WindowGLFW::Open(const String& title, unsigned int width, unsigned int height, Display* display)
{
    if (m_GraphicsDevice == nullptr)
    {
        return false;
    }

    if (IsOpen())
    {
        return false; // Window is already open!
    }

    m_Window = glfwCreateWindow(width, height, title.Raw(), (GLFWmonitor*)display, nullptr);
    if (m_Window == nullptr)
        return false; // Could not create a GLFW window!

    return true;
}

}