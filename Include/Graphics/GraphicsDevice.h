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

enum GraphicsAPI
{
	eOpenGL,
	eVulkan,
};

struct GraphicsOptions
{
	bool vSync;
};

class GraphicsDevice
{
public:
	GraphicsDevice(const GraphicsOptions& options);
	virtual ~GraphicsDevice() = 0;

	GraphicsAPI API();

// Window
public:
	// Returns the CURRENTLY displays connected to the device
	virtual const Array<Display*>& GetDisplays() = 0;

	// Setting a display will cause the window to go into fullscreen on desktops
	virtual Window* CreateWindow(const String& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, Display* display = nullptr) = 0;
	virtual void DestroyWindow(Window* window) = 0;

// Graphics
public:
	virtual VertexBuffer* CreateVertexBuffer(const VertexFormat& format, const void* vertices, unsigned int verticesCount) = 0;
	template <typename T> VertexBuffer* CreateVertexBuffer(const VertexFormat& format, const Array<T>& vertices) { return CreateVertexBuffer(format, vertices.Raw(), vertices.Count()); }
	virtual void DestroyVertexBuffer(VertexBuffer* buffer) = 0;

	virtual IndexBuffer* CreateIndexBuffer(const Array<unsigned short>& indices) = 0;
	virtual void DestroyIndexBuffer(IndexBuffer* buffer) = 0;

	virtual InstanceBuffer* CreateInstanceBuffer() = 0;
	virtual void DestroyInstanceBuffer() = 0;
	
	virtual Texture* CreateTexture(unsigned int width, unsigned int height, const Array<unsigned char>& pixels) = 0;
	virtual void DestroyTexture(Texture* texture) = 0;
	
	virtual Pipeline* CreatePipeline(const Array<unsigned char>& vertex, const Array<unsigned char>& fragment) = 0;
	virtual void DestroyPipeline(Pipeline* pipeline) = 0;

// Drawing
public:

	// Simple submission
	virtual void SetViewTransform(const Matrix4f& transform) = 0;
	virtual void SetViewFrustum(const Matrix4f& projection) = 0;
	virtual void SetModelTransform(const Matrix4f& transform) = 0;
	virtual void SetVertexBuffer(VertexBuffer* vertexBuffer) = 0;
	virtual void SetIndexBuffer(IndexBuffer* indexBuffer) = 0;
	virtual void SetPipeline(Pipeline* pipeline) = 0;
	virtual void SetState(State state) = 0;
	
	virtual void Submit(const Window& context) = 0; // Submits to the window frame queue

	// Use Window::NextFrame to draw to that surface
	// Use Window::Submit to submit directly to the surface 

public:
	GraphicsOptions options;
	Array<Resource*> resources; // Store resources and pipelines to ensure destruction later

};

GraphicsDevice* GraphicsDeviceInitialize(const GraphicsOptions& options);
void GraphicsDeviceTerminate(GraphicsDevice* graphicsDevice);

}