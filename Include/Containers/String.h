#pragma once

#include "Macro.h"
#include "Array.h"

namespace AE
{

class String
{

public:
	String();
	String(const String& other);
	String(const String&& other);

	String(const char* raw, int size);
	AE_UNSAFE String(const char* raw); // Unsafe
	
	~String();

public:
	void Set(String& other);
	void Set(const char* raw, int size);
	const char* Raw();
	void Append(String& other);
	void Clear();

private:
	Array<char> m_Arr;

};

}