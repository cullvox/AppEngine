#include "Graphics/GraphicsFactory.h"
#include "Graphics/OpenGL/GraphicsFactoryOpenGL.h"

namespace AE
{

IGraphicsFactory* CreateGraphicsFactory(const SGraphicsOptions& options)
{

	switch (options.api)
	{
	case EGraphicsAPI::eOpenGL:
		return new FGraphicsFactoryOpenGL(options);
		break;

	default:
		throw "Invalid graphics API!";
	}

	return nullptr;
}

} 