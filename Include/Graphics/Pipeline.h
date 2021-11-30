#pragma once

#include <vector>
#include <string>

#include "Resource.h"

namespace AE
{

class IGraphicsFactory;

class IPipeline : public IResource
{
	
public:
	IPipeline();
	IPipeline(IGraphicsFactory* factory, std::vector<unsigned char> vertex, std::vector<unsigned char> fragment);
	~IPipeline();
protected:
	IPipeline(const IPipeline& other);

public:
	virtual IPipeline* Clone();

public:
	void setVector4Parameter(const std::string& name, const SVector4f& value);
	void setMatrix4Parameter(const std::string& name, const SMatrix4f& value);

};

}