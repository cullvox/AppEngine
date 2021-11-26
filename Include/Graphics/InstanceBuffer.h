#pragma once

#include "Graphics/Resources.h"

namespace AE
{

class GraphicsDevice;

class InstanceBuffer
{
public:
	InstanceBuffer(GraphicsDevice* graphicsDevice, unsigned int instanceCount, unsigned int stride);
	~InstanceBuffer();

	void Bind(const GraphicsDevice& graphicsDevice) const;

	void Update(const GraphicsDevice& graphicsDevice, const void* data, const size_t size);
};

};