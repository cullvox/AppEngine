#pragma once

#include "Graphics/OpenGL/WindowOpenGL.h"
#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

// Not much really has to be done here since GLFW was built for OpenGL
class FWindowOpenGLGLFW final : public IWindowOpenGL, public IWindowGLFW
{

public:
	FWindowOpenGLGLFW(); // Default
	FWindowOpenGLGLFW(const FWindowOpenGLGLFW& window);
	FWindowOpenGLGLFW(IGraphicsFactory* factory, const SString& title, unsigned int width, unsigned int height, IDisplay* display);
	~FWindowOpenGLGLFW();

public:

public:
	IResource& operator=(const IResource& other);


};

}