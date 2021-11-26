#pragma once

#include "Resource.h"

namespace AE
{

class Texture : public Buffer
{

public:
	Texture(GraphicsDevice* device, unsigned char* data);
	~Texture();

};

}