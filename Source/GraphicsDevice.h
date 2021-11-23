#pragma once

#include "Array.h"

namespace AE
{

struct Vertex
{
	
};

class VertexBuffer
{

public:
	VertexBuffer(GraphcisDevice* device, );
	virtual ~VertexBuffer() = 0;

};

class GraphicsDevice
{

public:
	GraphicsDevice();
	virtual ~GraphicsDevice() = 0;

public:
	VertexBuffer* CreateVertexBuffer();
	void DestroyVertexBuffer(VertexBuffer* buffer);

	IndexBuffer* DestroyIndexBuffer();
};

}