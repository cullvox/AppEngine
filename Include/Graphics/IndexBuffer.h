#pragma once

#include <vector>

#include "Resource.h"

namespace AE
{

class IIndexBuffer : public IBuffer
{

public:
	IIndexBuffer();
	IIndexBuffer(const IIndexBuffer& other);
	IIndexBuffer(IGraphicsFactory* factory, std::vector<unsigned short> indices);
	~IIndexBuffer();

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	virtual IResource* operator=(const IResource* other);

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;
	virtual void Update(std::vector<unsigned short> indices) = 0;

};

}