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
	TArray<IDisplay*>	RetrieveDisplays();

	TUniquePointer<IWindow>			CreateWindow(const FString& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr);
	TUniquePointer<IVertexBuffer>	CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount);
	TUniquePointer<IIndexBuffer>	CreateIndexBuffer(const TArray<unsigned short>& indices);
	TUniquePointer<IInstanceBuffer>	CreateInstanceBuffer();
	TUniquePointer<ITexture>		CreateTexture(unsigned int width, unsigned int height, const TArray<unsigned char>& pixels);
	TUniquePointer<IPipeline>		CreatePipeline(const TArray<unsigned char>& vertex, const TArray<unsigned char>& fragment);

};

}