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
	void SetVector4Parameter(const String& name, const Vector4f& value);
	void SetMatrix4Parameter(const String& name, const Matrix4f& value);
	
};

}