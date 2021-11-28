#pragma once

#include "Containers/Array.h"
#include "Graphics/Resource.h"
#include "Graphics/Vertex.h"

namespace AE
{

class IVertexBuffer : public IBuffer
{
	
public:
	IVertexBuffer(); // Default
	IVertexBuffer(const IVertexBuffer& other); // Copy
	IVertexBuffer(IGraphicsFactory* factory, const VertexFormat& format, const void* , unsigned int size);
	virtual ~IVertexBuffer() = 0;

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* vertices, unsigned int vertexCount) = 0;
};

}