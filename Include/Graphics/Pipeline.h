#pragma once

#include "Containers/Array.h"
#include "Resource.h"

namespace AE
{

class Pipeline : public Resource
{
	
public:
	Pipeline();
	Pipeline(Array<unsigned char> vertex, Array<unsigned char> fragment);
	~Pipeline();

public:
	void Bind();

};

}