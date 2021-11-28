#include "Graphics/GraphicsFactory.h"
#include "Graphics/OpenGL/GraphicsFactoryOpenGL.h"

namespace AE
{

IGraphicsFactory* CreateGraphicsFactory(const SGraphicsOptions& options)
{

	switch (options.api)
	{
	case EGraphicsAPI::eOpenGL:
		
		break;

	default:
		break;
	}

}

}