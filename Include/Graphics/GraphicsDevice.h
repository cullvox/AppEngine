#pragma once

// GraphicsDevice.h
// Contains abstract classes as a format for apis.

#include "Types.h"
#include "Containers/Array.h"
#include "Containers/String.h"
#include "Graphics/Vertex.h"

namespace AE
{

struct GraphicsSubmit
{

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
	virtual VertexBuffer* CreateVertexBuffer(Array<Vertex> verts) = 0;
	virtual void DestroyVertexBuffer(VertexBuffer* buffer) = 0;

	virtual IndexBuffer* CreateIndexBuffer(Array<unsigned short> indices) = 0;
	virtual void DestroyIndexBuffer(IndexBuffer* buffer) = 0;
	
	virtual Texture* CreateTexture(unsigned int width, unsigned int height, Array<unsigned char> pixels) = 0;
	virtual void DestroyTexture(Texture* texture) = 0;
	
	virtual Pipeline* CreatePipeline(Array<unsigned char> vertex, Array<unsigned char> fragment) = 0;
	virtual void DestroyPipeline(Pipeline* pipeline) = 0;

// Drawing
public:
	virtual void UpdateTransform();
	virtual void UpdateProjection();
	virtual void Submit() = 0; // Submits to the frame queue
	virtual void NextFrame() = 0; // Submits the currently queued frames to the GPU

public:
	// Store resources and pipelines to ensure destruction later
	Array<Resource*> resources;

	// The draw calls to submit this frame
	Queue<GraphicsSubmit> frameSubmissions;
};

}