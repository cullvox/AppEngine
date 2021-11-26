#pragma once

#include "Containers/Array.h"
#include "Graphics/Resource.h"
#include "Graphics/Vertex.h"

namespace AE
{

class VertexBuffer : public Buffer
{
	
public:
	VertexBuffer();
	VertexBuffer(GraphicsDevice* device, const VertexFormat& format);
	virtual ~VertexBuffer() = 0;

public:
	virtual void Bind() = 0;

	virtual void Update(const Array<>& data) = 0;

};

}