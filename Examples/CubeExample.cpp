#include "Graphics/GraphicsFactory.h"

int main()
{
	AE::SGraphicsOptions graphicsOptions = {};
	AE::IGraphicsFactory* graphicsFactory = AE::CreateGraphicsFactory(graphicsOptions);
	AE::DestroyGraphicsFactory(graphicsFactory);
}