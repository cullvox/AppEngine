#pragma once

// Resource.h
// Contains object abstractions of runtime data that can be used when rendering

namespace AE
{

class IGraphicsFactory;

// Resources should be abstractions of API data and are basically handles
class IResource
{
	
public: // Constructors
	IResource(); // Default
	IResource(const IResource& other); // Preforms a Shallow Copy
	IResource(IGraphicsFactory* factory);
	virtual ~IResource() = 0;

protected: // Virtual Constructors
	virtual IResource* ShallowCopy(const IResource* other) = 0; // Copys the resources handles to this

public: // Operator Overloading
	virtual IResource& operator=(const IResource& other) = 0; // Shallow Copy Assignment

public: // Functions
	virtual void Bind() = 0;

protected: // Variables
	IGraphicsFactory* m_Factory;

public: // Friendship
	friend class IGraphicsFactory;

};

class IBuffer : public IResource
{

public:
	IBuffer(); // Default
	IBuffer(const IBuffer& other); // Copy
	IBuffer(IGraphicsFactory* factory);
	virtual ~IBuffer() = 0;

public:
	virtual void Bind() const = 0;
	virtual void Update(const void* data, unsigned int size) = 0;

protected:
	virtual IResource* ShallowCopy(const IResource* other) = 0;

};

}