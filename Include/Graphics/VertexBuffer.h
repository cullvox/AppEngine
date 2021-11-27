#pragma once

#include "Containers/Array.h"
#include "Graphics/Resource.h"
#include "Graphics/Vertex.h"

namespace AE
{

class VertexBuffer : public Buffer
{
	
public:
	VertexBuffer(); // Default
	VertexBuffer(const VertexBuffer& other); // Copy
	VertexBuffer(GraphicsDevice* device, const VertexFormat& format);
	virtual ~VertexBuffer() = 0;

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;
	virtual Buffer* Copy() = 0;
};

}