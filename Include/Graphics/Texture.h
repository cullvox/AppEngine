#pragma once

#include "Resource.h"

namespace AE
{

class ITexture : public IBuffer
{

public:
	ITexture();
	ITexture(IGraphicsFactory* factory, unsigned char* data);
	~ITexture();

public:
	virtual IResource* ShallowCopy(const IResource* other);

};

}