#include <GLFW/glfw3.h>
#include "Graphics/OpenGL/WindowGLFWOpenGL.h"

namespace AE
{

static void* GetLoadProc()
{
	return 
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW()
{
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW(const WindowGLFWOpenGL& other)
	: IWindowOpenGL(other), IWindowGLFW(other)
{
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW(IGraphicsFactory* factory, const SString& title, unsigned int width, unsigned int height, SDisplay* display)
	: WindowOpenGL(factory, title, width, height, display), WindowGLFW(factory, title, width, height, display)
{
}

FWindowOpenGLGLFW::~FWindowOpenGLGLFW()
	: ~WindowOpenGL(), ~WindowGLFW()
{
}



}