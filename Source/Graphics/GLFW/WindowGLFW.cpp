#include "Graphics/GLFW/Window_GLFW.h"

namespace AE
{

bool WindowSystemInitialize()
{
    if (glfwInit() != GLFW_TRUE)
    {
        return false;
    }
}

WindowGLFW::WindowGLFW()
{
}

WindowGLFW::WindowGLFW(GraphicsDevice* graphicsDevice, const String& title, unsigned int width, unsigned int height, Display* display)
{

}

WindowGLFW::~WindowGLFW();

bool WindowGLFW::Open(const String& title, unsigned int width, unsigned int height, Display* display)
{
    if (window == nullptr)
    {
        return true;
    }
}

}