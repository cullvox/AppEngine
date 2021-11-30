#pragma once

namespace AE
{

class ICloneable
{

public:
	ICloneable();
	virtual ~ICloneable() = 0;
protected:
	ICloneable(const ICloneable&); // Redefine this in cloned class

public:
	virtual ICloneable* Clone() = 0;

};

}