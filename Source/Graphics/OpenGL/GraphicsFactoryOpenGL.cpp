#include <glad/glad.h>

#include <IO/Logger.h>

#include "Graphics/OpenGL/WindowOpenGLGLFW.h"
#include "Graphics/OpenGL/GraphicsFactoryOpenGL.h"

namespace AE
{

static bool g_GladInitialized = false;
bool CheckAndInitializeGLAD()
{
	if (!g_GladInitialized)
	{
		if (!gladLoadGLLoader((GLADloadproc)IWindowOpenGL::GetLoadProc()))
		{
			LOG_ERROR("Could not load GLAD!");
			return false;
		}

		g_GladInitialized = true;
	}

	return true;
}

FGraphicsFactoryOpenGL::FGraphicsFactoryOpenGL(const FGraphicsOptions& options)
{
	m_Options = options;
}

FGraphicsFactoryOpenGL::~FGraphicsFactoryOpenGL()
{
}

std::unique_ptr<IWindow> FGraphicsFactoryOpenGL::CreateWindow(const std::string& title, unsigned int width, unsigned int height, IDisplay* display)
{
	std::unique_ptr<IWindow> window = std::unique_ptr<IWindow>((IWindow*)(IWindowOpenGL*)new FWindowOpenGLGLFW(this, title, width, height, display));

	if (!CheckAndInitializeGLAD())
	{
		return nullptr;
	}

	return std::move(window);
}

std::unique_ptr<IVertexBuffer> FGraphicsFactoryOpenGL::CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount)
{
	return nullptr;
}

std::unique_ptr<IIndexBuffer> FGraphicsFactoryOpenGL::CreateIndexBuffer(const std::vector<unsigned short>& indices)
{
	return nullptr;
}

std::unique_ptr<IInstanceBuffer> FGraphicsFactoryOpenGL::CreateInstanceBuffer()
{
	return nullptr;
}

std::unique_ptr<ITexture> FGraphicsFactoryOpenGL::CreateTexture(unsigned int width, unsigned int height, const std::vector<unsigned char>& pixels)
{
	return nullptr;
}

std::unique_ptr<IPipeline> FGraphicsFactoryOpenGL::CreatePipeline(const std::vector<unsigned char>& vertex, const std::vector<unsigned char>& fragment)
{
	return nullptr;
}

}