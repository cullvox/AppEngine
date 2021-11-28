#pragma once

#include "Graphics/GraphicsFactory.h"

namespace AE
{

class FGraphicsFactoryOpenGL final : public IGraphicsFactory
{

public:
	FGraphicsFactoryOpenGL(const SGraphicsOptions& options);
	~FGraphicsFactoryOpenGL();

public:
	IWindow*			CreateWindow(const SString& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr);
	IVertexBuffer*		CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount);
	IInstanceBuffer*	CreateInstanceBuffer();
	ITexture*			CreateTexture(unsigned int width, unsigned int height, const TArray<unsigned char>& pixels);
	IPipeline*			CreatePipeline(const TArray<unsigned char>& vertex, const TArray<unsigned char>& fragment);
	

};

}