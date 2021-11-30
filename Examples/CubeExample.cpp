#include "Graphics/GraphicsFactory.h"

int main()
{
	AE::SGraphicsOptions graphicsOptions = {};
	std::unique_ptr<AE::IGraphicsFactory> graphicsFactory = AE::CreateGraphicsFactory(graphicsOptions);
}