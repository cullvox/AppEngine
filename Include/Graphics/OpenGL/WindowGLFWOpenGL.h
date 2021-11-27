#pragma once

#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

// Not much really has to be done here since GLFW was build for OpenGL
class WindowGLFWOpenGL : public WindowGLFW
{

public:
    WindowGLFWOpenGL(); // Default
    WindowGLFWOpenGL(const WindowGLFWOpenGL& window);
    WindowGLFWOpenGL(GraphicsDevice* graphicsDevice, const String& title, unsigned int width, unsigned int height, Display* display);
    ~WindowGLFWOpenGL();

public:
    

};

}