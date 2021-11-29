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
	ShallowCopy(static_cast<const IResource*>(&other));
}

FWindowOpenGLGLFW::FWindowOpenGLGLFW(IGraphicsFactory* factory, const FString& title, unsigned int width, unsigned int height, IDisplay* display)
	: IWindowOpenGL(factory, title, width, height, display), IWindowGLFW(factory, title, width, height, display)
{
}

FWindowOpenGLGLFW::~FWindowOpenGLGLFW()
{
}

IResource* FWindowOpenGLGLFW::ShallowCopy(const IResource* other)
{
	IWindowOpenGL::ShallowCopy(other);
	IWindowGLFW::ShallowCopy(other);
	return this;
}

}