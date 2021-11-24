#pragma once

#include "Resource.h"

namespace AE
{

class Texture : public Resource
{

public:
	Texture(GraphicsDevice* device, unsigned char* data);
	~Texture();

};

}