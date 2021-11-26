#pragma once

namespace AE
{

class GraphicsDevice;

class Resource
{
	
public:
	Resource();
	virtual ~Resource() = 0;

public:
	virtual void Bind() = 0;

public:
	friend class GraphicsDevice;

};

class Buffer : public Resource
{

public:
	Buffer();
	virtual ~Buffer() = 0;

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;

};

}