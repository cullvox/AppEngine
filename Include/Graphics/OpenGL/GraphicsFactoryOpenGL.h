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
	std::vector<IDisplay*>	RetrieveDisplays();

	std::unique_ptr<IWindow>			CreateWindow(const std::string& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr);
	std::unique_ptr<IVertexBuffer>		CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount);
	std::unique_ptr<IIndexBuffer>		CreateIndexBuffer(const std::vector<unsigned short>& indices);
	std::unique_ptr<IInstanceBuffer>	CreateInstanceBuffer();
	std::unique_ptr<ITexture>			CreateTexture(unsigned int width, unsigned int height, const std::vector<unsigned char>& pixels);
	std::unique_ptr<IPipeline>			CreatePipeline(const std::vector<unsigned char>& vertex, const std::vector<unsigned char>& fragment);

};

}