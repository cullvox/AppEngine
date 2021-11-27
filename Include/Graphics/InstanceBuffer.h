#pragma once

#include "Graphics/Resource.h"

namespace AE
{

class GraphicsDevice;

class InstanceBuffer
{
public:
	InstanceBuffer();
	InstanceBuffer(GraphicsDevice* graphicsDevice, unsigned int instanceCount, unsigned int stride);
	~InstanceBuffer();

public:
	virtual void Bind(const GraphicsDevice& graphicsDevice) const = 0;
	virtual void Update(const void* data, const size_t size) = 0;
};

};