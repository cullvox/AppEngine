#pragma once

#include "NonCopyable.h"

namespace AE
{

class IGlobalInitializer
{
public:
	IGlobalInitializer() {};
	virtual ~IGlobalInitializer() = 0 {};
};

}