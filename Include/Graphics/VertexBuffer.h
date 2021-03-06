#pragma once

#include "Graphics/Resource.h"
#include "Graphics/Vertex.h"

namespace AE
{

class IVertexBuffer : public IBuffer
{
	
public:
	IVertexBuffer(); // Default
	IVertexBuffer(const IVertexBuffer& other); // Copy
	IVertexBuffer(IGraphicsFactory* factory, const VertexFormat& format, const void* vertices, unsigned int verticesCount);
	virtual ~IVertexBuffer() = 0;

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* vertices, unsigned int vertexCount) = 0;
};

}