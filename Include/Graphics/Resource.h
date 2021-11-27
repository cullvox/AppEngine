#pragma once

// Resource.h
// Contains object abstractions of runtime data that can be used when rendering

namespace AE
{

class GraphicsDevice;

// Resources should be abstractions of API data and are basically handles
class Resource
{
	
public:
	Resource(); // Default
	Resource(const Resource& other); // Copy

	Resource(GraphicsDevice* graphicsDevice);
	virtual ~Resource() = 0;

public:
	virtual void Bind() = 0;

public:
	friend class GraphicsDevice;

};

class Buffer : public Resource
{

public:
	Buffer(); // Default
	Buffer(const Resource& other); // Copy

	Buffer(GraphicsDevice* graphicsDevice);
	virtual ~Buffer() = 0;

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;
	virtual Buffer* Copy(); // Creates a new buffer
};

}