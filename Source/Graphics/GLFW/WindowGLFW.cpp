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

IDisplayGLFW::IDisplayGLFW()
{
}

IDisplayGLFW::IDisplayGLFW(const IDisplay& other)
{
}

IDisplayGLFW::IDisplayGLFW(GLFWmonitor* monitor)
{
	m_Monitor = monitor;
}

const TArray<SVideoMode>& IDisplayGLFW::GetVideoModes()
{

	if (!bGotModes)
	{
		// Update video modes
		int count = 0;
		const GLFWvidmode* videoModes = glfwGetVideoModes(m_Monitor, &count);

		for (int i = 0; i < count; i++)
		{
			m_Modes.Push(SVideoMode(videoModes[i].width, videoModes[i].height, videoModes[i].refreshRate));
		}
		bGotModes = true;
	}

	return m_Modes;
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
		gDisplays.Push(otherDisp); 
		// gDisplays.Push(static_cast<IDisplay*>(display)); Will not work because its expecting an object reference
		// I wonder how I can fix this?
	}

	return TArray<IDisplay*>(gDisplays);
}

void IWindowGLFW::Bind()
{
	glfwMakeContextCurrent(m_Window);
}

void IWindowGLFW::Resize(unsigned int width, unsigned int height)
{
	glfwSetWindowSize(m_Window, width, height);
}

void IWindowGLFW::SetTitle(const SString& title)
{
	glfwSetWindowTitle(m_Window, title.Raw());
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