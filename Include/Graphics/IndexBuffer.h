#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class IIndexBuffer : public IBuffer
{

public:
	IIndexBuffer();
	IIndexBuffer(const IIndexBuffer& other);
	IIndexBuffer(IGraphicsFactory* factory, TArray<unsigned short> indices);
	~IIndexBuffer();

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	virtual IResource* operator=(const IResource* other);

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;
	virtual void Update(TArray<unsigned short> indices) = 0;

};

}