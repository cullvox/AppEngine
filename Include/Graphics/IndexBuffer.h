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
	virtual void Bind() = 0;

};

}