#pragma once

// GraphicsDevice.h
// Contains abstract classes as a format for apis.

#include "Types.h"
#include "Math/Matrix.h"
#include "Containers/Array.h"
#include "Containers/String.h"
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

struct SGraphicsOptions
{
	EGraphicsAPI api;
	bool vSync;
};

class IGraphicsFactory : public INonCopyable
{

public:
	IGraphicsFactory(const SGraphicsOptions& options = {});
	virtual ~IGraphicsFactory() = 0;

public:
	EGraphicsAPI GetAPI() const 
	{ return m_API; }

	virtual IWindow*			CreateWindow(const SString& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr) = 0; // Setting a display will cause the window to go into fullscreen on desktops
	virtual IVertexBuffer*		CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount) = 0;
	virtual IInstanceBuffer*	CreateInstanceBuffer() = 0;
	virtual ITexture*			CreateTexture(unsigned int width, unsigned int height, const TArray<unsigned char>& pixels) = 0;
	virtual IPipeline*			CreatePipeline(const TArray<unsigned char>& vertex, const TArray<unsigned char>& fragment) = 0;

	// Alternative create functions
	template <typename T>
	IVertexBuffer*				CreateVertexBuffer(const VertexFormat& format, const TArray<T>& vertices) 
	{ return CreateVertexBuffer(format, vertices.Raw(), vertices.Count()); }

protected:
	EGraphicsAPI m_API;
	SGraphicsOptions m_Options;
	TArray<IResource*> m_Resources; // Store all resources to ensure destruction later
	TArray<IWindow*> m_Windows; // Store windows for rendering

};

IGraphicsFactory* CreateGraphicsFactory(const SGraphicsOptions& options);
void DestroyGraphicsFactory(IGraphicsFactory* graphicsFactory);

#define CHECK_GRAPHICS_FACTORY(factory) if (factory == NULL && (factory->GetAPI() <= EGraphicsAPI::eMAX)  ) { throw; }

}