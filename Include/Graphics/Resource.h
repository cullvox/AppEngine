#pragma once

#include "Cloneable.h"

// Resource.h
// Contains object abstractions of runtime data that can be used when rendering

namespace AE
{

class IGraphicsFactory;

// Resources should be abstractions of API data and are basically handles
class IResource : public virtual ICloneable
{
	
public:
	IResource();
	IResource(IGraphicsFactory* factory);
	virtual ~IResource() {};
protected:
	IResource(const IResource& other);

public:
	virtual IResource* Clone() = 0; // Clones only handles
	virtual void Bind() = 0;

protected:
	IGraphicsFactory* m_Factory;
public:
	friend class IGraphicsFactory;

};

class IBuffer : public IResource
{

public:
	IBuffer();
	IBuffer(IGraphicsFactory* factory);
	virtual ~IBuffer() {};

protected:
	IBuffer(const IBuffer& other);

public:
	virtual IBuffer* Clone() = 0;
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;

};

}