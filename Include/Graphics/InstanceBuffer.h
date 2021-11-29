#pragma once

#include "Graphics/Resource.h"

namespace AE
{

class GraphicsDevice;

class IInstanceBuffer
{
public:
	IInstanceBuffer(); // Default
	IInstanceBuffer(const IInstanceBuffer& other); // Copy
	IInstanceBuffer(IGraphicsFactory* factory, unsigned int instanceCount, unsigned int stride);
	~IInstanceBuffer();

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, const size_t size) = 0;
};

};