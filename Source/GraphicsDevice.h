#pragma once

// GraphicsDevice.h
// Contains abstract classes as a format for apis.

#include "Array.h"
#include "Vector.h"

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

class PipelineInstance : public Resource
{
public:
	PipelineInstance();
	PipelineInstance(GraphicsDevice& device, Pipeline& pipeline);

public:
	void Bind();
};

class GraphicsDevice
{
public:
	GraphicsDevice();
	virtual ~GraphicsDevice() = 0;

public:
	virtual VertexBuffer* CreateVertexBuffer() = 0;
	virtual void DestroyVertexBuffer(VertexBuffer* buffer) = 0;

	virtual IndexBuffer* CreateIndexBuffer() = 0;
	virtual void DestroyIndexBuffer(IndexBuffer* buffer) = 0;
	

public:
	// Store resources and pipelines to ensure destruction later
	Array<Resource*> resources;

};

}