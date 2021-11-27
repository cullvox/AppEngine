#pragma once

#include <GLFW/glfw3.h>

#include "Graphics/Window.h"

namespace AE
{

class WindowGLFW : public Window
{

public:
    WindowGLFW(); // Default
    WindowGLFW(const WindowGLFW& other); // Copy
    WindowGLFW(GraphicsDevice* graphicsDevice, const String& title, unsigned int width, unsigned int height, Display* display);
    ~WindowGLFW();

public:
    bool IsOpen();
    bool Open(const String& title, unsigned int width, unsigned int height, Display* display);
    void Close();

    void Bind();
    void Resize(unsigned int width, unsigned int height);
    void SetTitle(const String& title);

private:
    GLFWwindow* m_Window = nullptr;

};

}