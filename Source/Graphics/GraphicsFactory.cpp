#include "Graphics/GraphicsFactory.h"
#include "Graphics/OpenGL/GraphicsFactoryOpenGL.h"

namespace AE
{

std::unique_ptr<IGraphicsFactory> CreateGraphicsFactory(const SGraphicsOptions& options)
{

	switch (options.api)
	{
	case EGraphicsAPI::eOpenGL:
		return std::unique_ptr<IGraphicsFactory>(new FGraphicsFactoryOpenGL(options));
		break;

	default:
		throw "Invalid graphics API!";
	}

	return nullptr;
}

} 