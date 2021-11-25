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
	void SetIntParameter(const String& name, int value);
	void SetFloatParameter(const String& name, float value);
	void SetVector2Parameter(const String& name, const Vector2f& value);
	void SetVector3Parameter(const String& name, const Vector3f& value);
	void SetVector4Parameter(const String& name, const Vector4f& value);
	void SetMatrix4Parameter(const String& name, const Matrix4f& value);
	
};

}