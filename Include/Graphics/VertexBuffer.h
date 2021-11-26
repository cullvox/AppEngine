#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class VertexBuffer : public Buffer
{
	
public:
	VertexBuffer();
	template<class T>
	VertexBuffer(GraphicsDevice* device, Array<VertexType> vertices);
	virtual ~VertexBuffer() = 0;

public:
	virtual void Bind() = 0;

};

}