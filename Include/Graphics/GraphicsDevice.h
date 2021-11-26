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

struct GraphicsOptions
{
	bool vSync;

};

class GraphicsDevice
{
public:
	GraphicsDevice();
	virtual ~GraphicsDevice() = 0;

// Window
public:
	// Returns the CURRENTLY displays connected to the device
	virtual const Array<Display*>& GetDisplays() = 0;

	// Setting a display will cause the window to go into fullscreen on desktops
	virtual Window* CreateWindow(const String& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, Display* display = nullptr) = 0;
	virtual void DestroyWindow(Window* window) = 0;

// Graphics
public:
	virtual VertexBuffer* CreateVertexBuffer(const Array<Vertex>& vertices) = 0;
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

	// Add submission to the queue
	virtual void SetViewTransform(const Matrix4f& transform) = 0;
	virtual void SetViewFrustrum(const Matrix4f& projection) = 0;
	virtual void SetModelTransform(const Matrix4f& transform) = 0;
	virtual void SetVertexBuffer(VertexBuffer* vertexBuffer) = 0;
	virtual void SetIndexBuffer(IndexBuffer* indexBuffer) = 0;
	virtual void SetPipeline(Pipeline* pipeline) = 0;
	virtual void SetState(State state) = 0;
	
	virtual void Submit(Pipeline* pipeline) = 0; // Submits to the frame queue
	virtual void Submit(const Submission& submission, const Window& context) = 0; // Direct submission

	virtual void NextFrame(const Window& context) = 0; // Submits the currently queued frames to the GPU

public:
	GraphicsOptions options;
	Array<Resource*> resources; // Store resources and pipelines to ensure destruction later

};

}