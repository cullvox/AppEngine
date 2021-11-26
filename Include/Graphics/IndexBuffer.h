#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class IndexBuffer : public Buffer
{

public:
	IndexBuffer(GraphicsDevice* device, Array<unsigned short> indices);
	~IndexBuffer();

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;
	virtual void Update(Array<unsigned short> indices) = 0;

};

}