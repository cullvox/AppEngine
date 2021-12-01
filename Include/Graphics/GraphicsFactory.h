#pragma once

// GraphicsDevice.h
// Contains abstract classes as a format for apis.

#include <memory>
#include <vector>

#include "NonCopyable.h"
#include "Math/Matrix.h"
#include "Containers/Queue.h"
#include "Graphics/Window.h"
#include "Graphics/Vertex.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Texture.h"
#include "Graphics/Pipeline.h"

namespace AE
{

enum class EGraphicsAPI : uint8_t
{
	eOpenGL,
	eVulkan,
	eMAX = eVulkan,
};

struct FGraphicsOptions
{
	FGraphicsOptions()
		: api(EGraphicsAPI::eOpenGL), bVerticalSync(false)
	{
	}

	FGraphicsOptions(EGraphicsAPI _api, bool _bVerticalSync)
		: api(_api), bVerticalSync(_bVerticalSync)
	{
	}


	EGraphicsAPI api;
	bool bVerticalSync;
};

class IGraphicsFactory : public INonCopyable
{

public:
	IGraphicsFactory(const FGraphicsOptions& options = {}) {};
	virtual ~IGraphicsFactory() {};

public:
	EGraphicsAPI GetAPI() const 
	{ return m_API; }

	virtual std::unique_ptr<IWindow>			CreateWindow(const std::string& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr) = 0; // Setting a display will cause the window to go into fullscreen on desktops
	virtual std::unique_ptr<IVertexBuffer>		CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount) = 0;
	virtual std::unique_ptr<IIndexBuffer>		CreateIndexBuffer(const std::vector<unsigned short>& indices);
	virtual std::unique_ptr<IInstanceBuffer>	CreateInstanceBuffer() = 0;
	virtual std::unique_ptr<ITexture>			CreateTexture(unsigned int width, unsigned int height, const std::vector<unsigned char>& pixels) = 0;
	virtual std::unique_ptr<IPipelineBuilder>	CreatePipelineBuilder()
	virtual std::unique_ptr<IPipeline>			CreatePipeline(const std::vector<unsigned char>& vertex, const std::vector<unsigned char>& fragment) = 0;

	// Alternative create functions
	template <typename T>
	std::unique_ptr<IVertexBuffer>			CreateVertexBuffer(const VertexFormat& format, const std::vector<T>& vertices) 
	{ return CreateVertexBuffer(format, vertices.Raw(), vertices.Count()); }

protected:
	EGraphicsAPI m_API;
	FGraphicsOptions m_Options;
	std::vector<IResource*> m_Resources; // Store all resources to ensure destruction later
	std::vector<IWindow*> m_Windows; // Store windows for rendering

};

std::unique_ptr<IGraphicsFactory> CreateGraphicsFactory(const FGraphicsOptions& options);
void DestroyGraphicsFactory(IGraphicsFactory* graphicsFactory);

#define CHECK_GRAPHICS_FACTORY(factory) if (factory == NULL && (factory->GetAPI() <= EGraphicsAPI::eMAX)  ) { throw; }

}