#include "Graphics/GraphicsFactory.h"
#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

static TArray<IDisplay*> gDisplays;

bool WindowSystemInitialize()
{
	return glfwInit();
}

void WindowSystemFreeDisplays()
{
	for (unsigned int i = 0; i < gDisplays.Count(); i++)
	{
		delete gDisplays[i];
	}

	gDisplays.Clear();
}

void WindowSystemTerminate()
{
	WindowSystemFreeDisplays();
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

const TArray<IDisplay*> IWindow::GetCurrentDisplays()
{
	WindowSystemFreeDisplays();

	// Update displays
	int monitorsCount = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&monitorsCount);

	for (int i = 0 ; i < monitorsCount; i++)
	{
		// TODO: Make this less weird
		IDisplayGLFW* display = new IDisplayGLFW(monitors[i]);
		IDisplay* otherDisp = static_cast<IDisplay*>(display);
		gDisplays.Push(otherDisp); // gDisplays.Push(static_cast<IDisplay*>(display)); Will not work because its expecting an object reference
	}

	return TArray<IDisplay*>(gDisplays);
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