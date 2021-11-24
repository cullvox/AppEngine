#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class VertexBuffer : public Buffer
{
	
public:
	VertexBuffer();
	VertexBuffer(GraphicsDevice* device, Array<Vertex> verts);
	virtual ~VertexBuffer() = 0;

public:
	void Bind();

};

}