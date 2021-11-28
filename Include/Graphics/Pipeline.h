#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class IGraphicsFactory;

class IPipeline : public IResource
{
	
public:
	IPipeline();
	IPipeline(const IPipeline& other); // Copy Handle
	IPipeline(IGraphicsFactory* factory, TArray<unsigned char> vertex, TArray<unsigned char> fragment);
	~IPipeline();

public:
	void setVector4Parameter(const SString& name, const SVector4f& value);
	void setMatrix4Parameter(const SString& name, const SMatrix4f& value);

};

}