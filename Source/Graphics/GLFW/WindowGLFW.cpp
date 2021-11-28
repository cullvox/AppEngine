#include "Graphics/GraphicsFactory.h"
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

IWindowGLFW::IWindowGLFW()
{
}

IWindowGLFW::IWindowGLFW(const IWindowGLFW& other)
	: m_Window(other.m_Window)
{
}

IWindowGLFW::IWindowGLFW(IGraphicsFactory* factory, const SString& title, unsigned int width, unsigned int height, IDisplay* display)
{
	CHECK_GRAPHICS_FACTORY(factory)

	m_Window = glfwCreateWindow(width, height, title.Raw(), (GLFWmonitor*)display, nullptr);

	if (m_Window == nullptr)
		throw;

}

IWindowGLFW::~IWindowGLFW()
{
	glfwDestroyWindow(m_Window);
}

void IWindowGLFW::Bind()
{

}

void IWindowGLFW::Resize(unsigned int width, unsigned int height)
{

}

void IWindowGLFW::SetTitle(const SString& title)
{

}

void* IWindowGLFW::GetNative() const
{
	return m_Window;
}

IResource* IWindowGLFW::ShallowCopy(const IResource* other)
{
	m_Window = dynamic_cast<const IWindowGLFW*>(other)->m_Window;
	return this;
}

}