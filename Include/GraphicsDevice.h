#pragma once

// GraphicsDevice.h
// Contains abstract classes as a format for apis.

#include "Array.h"
#include "Vector.h"
#include "String.h"
#include "Types.h"

namespace AE
{

class GraphicsDevice;

struct Vertex
{
	Vector3f position;
	Vector3f normal;
};

class Resource
{
public:
	Resource();
	virtual ~Resource() = 0;
public:
	virtual void Bind() = 0;
public:
	friend class GraphicsDevice;
};

class Buffer : public Resource
{
public:
	Buffer();
	virtual ~Buffer() = 0;
};

class VertexBuffer : public Buffer
{
public:
	VertexBuffer(GraphicsDevice& device);
	VertexBuffer(GraphicsDevice& device, Array<Vertex> verts);
	~VertexBuffer();
public:
	void Bind();
};

class IndexBuffer : public Buffer
{
public:
	IndexBuffer();
	IndexBuffer(GraphicsDevice& device, Array<unsigned short> indices);
	~IndexBuffer();
public:
	void Bind();
};

class Texture : public Resource
{
public:
	Texture(GraphicsDevice& device, unsigned char* data);
	~Texture();
};

class Pipeline : public Resource
{
public:
	Pipeline();
	Pipeline(Array<unsigned char> vertex, Array<unsigned char> fragment);
	~Pipeline();
public:
	void Bind();
};

class Monitor : public NonCopyable
{

};

class Window : public Resource
{
public:
	Window();
	Window(GraphicsDevice& device, const String& name, unsigned int width, unsigned int height);
	virtual ~Window() = 0;

public:
	void Bind();
	void Resize(unsigned int width, unsigned int height);

}

class GraphicsDevice
{
public:
	GraphicsDevice();
	virtual ~GraphicsDevice() = 0;

// Window
public:
	virtual Window* CreateWindow() = 0;
	virtual void DestroyWindow() = 0;


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
	virtual void NextFrame() = 0;

public:
	// Store resources and pipelines to ensure destruction later
	Array<Resource*> resources;

};

}