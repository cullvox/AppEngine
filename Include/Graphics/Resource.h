#pragma once

// Resource.h
// Contains object abstractions of runtime data that can be used when rendering

namespace AE
{

class IGraphicsDevice;

// Resources should be abstractions of API data and are basically handles
class IResource
{
	
public:
	IResource(); // Default
	IResource(const IResource& other); // Shallow Copy of handles
	IResource(GraphicsDevice* graphicsDevice);
	virtual ~IResource() = 0;

public:
	virtual IResource& operator=(const IResource& other) = 0; // Shallow Copy Assignment

public:
	virtual void copy() = 0; // Preforms a deep copy of a resource
	virtual void bind() = 0;



public:
	friend class IGraphicsDevice;

protected:
	virtual IResource* shallowCopy(const IResource* other) = 0; // Copys the resources handles to this

protected:
	IGraphicsDevice* m_GraphicsDevice;

};

class IBuffer : public IResource
{

public:
	IBuffer(); // Default
	IBuffer(const IBuffer& other); // Copy

	IBuffer(IGraphicsDevice* graphicsDevice);
	virtual ~IBuffer() = 0;

public:
	virtual void bind() const = 0;
	virtual void update(const void* data, unsigned int size) = 0;
	virtual IBuffer* copy() = 0; // Creates a new buffer

protected:
	virtual IResource* shallowCopy(const IResource* other) = 0;

};

}