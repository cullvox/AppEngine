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

IWindow* FGraphicsFactoryOpenGL::CreateWindow(const SString& title, unsigned int width, unsigned int height, IDisplay* display)
{
	FWindowOpenGLGLFW* window = new FWindowOpenGLGLFW();
	return 
}

}