#include <glad/glad.h>

#include "Graphics/OpenGL/WindowOpenGLGLFW.h"
#include "Graphics/OpenGL/GraphicsFactoryOpenGL.h"

namespace AE
{

bool CheckAndInitializeGLAD()
{
	static bool gladInitialized = false;
	if (gladInitialized)
	{
		return true;
	}

	if (gladLoadGLLoader((GLADloadproc)IWindowOpenGL::GetLoadProc()))
	{
		gladInitialized = true;
		return true;
	}

	return false;
}

FGraphicsFactoryOpenGL::FGraphicsFactoryOpenGL(const SGraphicsOptions& options)
{	
}

FGraphicsFactoryOpenGL::~FGraphicsFactoryOpenGL()
{
}

TUniquePointer<IWindow> FGraphicsFactoryOpenGL::CreateWindow(const FString& title, unsigned int width, unsigned int height, IDisplay* display)
{
	FWindowOpenGLGLFW* window = new FWindowOpenGLGLFW();

	if (!CheckAndInitializeGLAD())
	{
		delete window;
		return nullptr;
	}

	return window;
}

TUniquePointer<IVertexBuffer> FGraphicsFactoryOpenGL::CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount)
{
	return nullptr;
}

TUniquePointer<IIndexBuffer> FGraphicsFactoryOpenGL::CreateIndexBuffer(const TArray<unsigned short>& indices)
{
	return nullptr;
}

TUniquePointer<IInstanceBuffer> FGraphicsFactoryOpenGL::CreateInstanceBuffer()
{
	return nullptr;
}

TUniquePointer<ITexture> FGraphicsFactoryOpenGL::CreateTexture(unsigned int width, unsigned int height, const TArray<unsigned char>& pixels)
{
	return nullptr;
}

TUniquePointer<IPipeline> FGraphicsFactoryOpenGL::CreatePipeline(const TArray<unsigned char>& vertex, const TArray<unsigned char>& fragment)
{
	return nullptr;
}

}