#include "GlobalInitializer.h"
#include "IO/Logger.h"
#include "Graphics/GraphicsFactory.h"
#include "Graphics/GLFW/WindowGLFW.h"

namespace AE
{

class FGLFWGlobalInitializer final : virtual public IGlobalInitializer
{
public:
	FGLFWGlobalInitializer()
	{
		if (!glfwInit())
		{
			LOG_ERROR("Could not init GLFW!");
			throw;
		}
	}

	~FGLFWGlobalInitializer();
};

void WindowSystemTerminate()
{
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

IDisplayGLFW* IDisplayGLFW::Clone()
{
	return new IDisplayGLFW(m_Monitor);
}

const std::vector<FVideoMode>& IDisplayGLFW::GetVideoModes()
{

	if (!bGotModes)
	{
		// Update video modes
		int count = 0;
		const GLFWvidmode* videoModes = glfwGetVideoModes(m_Monitor, &count);

		for (int i = 0; i < count; i++)
		{
			m_Modes.push_back(FVideoMode(videoModes[i].width, videoModes[i].height, videoModes[i].refreshRate));
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

IWindowGLFW::IWindowGLFW(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display)
{
	CHECK_GRAPHICS_FACTORY(factory)

	m_Window = glfwCreateWindow(width, height, title.c_str(), (GLFWmonitor*)display->GetNative(), nullptr);

	if (m_Window == nullptr)
		throw;

}

IWindowGLFW::~IWindowGLFW()
{
	glfwDestroyWindow(m_Window);
}

const std::vector<std::unique_ptr<IDisplay>>& IWindowGLFW::GetCurrentDisplays()
{
	mg_Displays.clear();

	// Update displays
	int monitorsCount = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&monitorsCount);

	for (int i = 0 ; i < monitorsCount; i++)
		mg_Displays.push_back(std::make_unique<IDisplayGLFW>(IDisplayGLFW(monitors[i])));

	return mg_Displays;
}

void IWindowGLFW::Bind()
{
	glfwMakeContextCurrent(m_Window);
}

void IWindowGLFW::Resize(unsigned int width, unsigned int height)
{
	glfwSetWindowSize(m_Window, width, height);
}

void IWindowGLFW::SetTitle(const std::string& title)
{
	glfwSetWindowTitle(m_Window, title.c_str());
}

void* IWindowGLFW::GetNative() const
{
	return m_Window;
}

}