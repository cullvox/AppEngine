#include <GLFW/glfw3.h>
#include "Graphics/OpenGL/WindowOpenGLGLFW.h"

namespace AE
{

void* IWindowOpenGL::GetLoadProc()
{
	return glfwGetProcAddress;
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW()
{
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW(const FWindowOpenGLGLFW& other)
	: IWindowOpenGL(other), IWindowGLFW(other)
{
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display)
	: IWindowOpenGL(factory, title, width, height, display), IWindowGLFW(factory, title, width, height, display)
{
}

FWindowOpenGLGLFW::~FWindowOpenGLGLFW()
{
}

FWindowOpenGLGLFW* FWindowOpenGLGLFW::Clone()
{
	return new FWindowOpenGLGLFW(*this);
}

}