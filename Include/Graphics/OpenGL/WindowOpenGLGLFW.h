#pragma once

#include <string>

#include "Suppress.h"
#include "Graphics/OpenGL/WindowOpenGL.h"
#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

// Not much really has to be done here since GLFW was built for OpenGL
class FWindowOpenGLGLFW final : public IWindowOpenGL, public IWindowGLFW
{

public:
	FWindowOpenGLGLFW();
	FWindowOpenGLGLFW(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display);
	~FWindowOpenGLGLFW();
protected:
	FWindowOpenGLGLFW(const FWindowOpenGLGLFW& window);

public:
	FWindowOpenGLGLFW* Clone();

};

}