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

	~FGLFWGlobalInitializer()
	{
		glfwTerminate();
	}
};

IDisplayGLFW::IDisplayGLFW()
{
}

IDisplayGLFW::IDisplayGLFW(GLFWmonitor* monitor)
{
	m_Monitor = monitor;
}

IDisplayGLFW::IDisplayGLFW(const IDisplayGLFW& other)
	: m_Monitor(other.m_Monitor), m_VideoModes(other.m_VideoModes)
{
}

IDisplayGLFW::~IDisplayGLFW()
{
}

IDisplayGLFW* IDisplayGLFW::Clone()
{
	return new IDisplayGLFW(m_Monitor);
}

const void* IDisplayGLFW::GetNative() const
{
	return m_Monitor;
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
			m_VideoModes.push_back(FVideoMode(videoModes[i].width, videoModes[i].height, videoModes[i].refreshRate));
		}
		bGotModes = true;
	}

	return m_VideoModes;
}

IWindowGLFW::IWindowGLFW()
{
	if (m_Window != nullptr)
		glfwDestroyWindow(m_Window);
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

static std::vector<std::unique_ptr<IDisplay>> g_Displays;

const std::vector<std::unique_ptr<IDisplay>>& IWindowGLFW::GetCurrentDisplays()
{
	g_Displays.clear();

	// Update displays
	int monitorsCount = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&monitorsCount);

	for (int i = 0 ; i < monitorsCount; i++)
		g_Displays.push_back(std::make_unique<IDisplayGLFW>(IDisplayGLFW(monitors[i])));

	return g_Displays;
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