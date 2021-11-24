#pragma once

#include "Macro.h"
#include "Array.h"

namespace AE
{

class StringRawUtils
{
public:
	static unsigned int Size(const char* raw, unsigned int MAX);
	static unsigned int AE_UNSAFE Size(const char* raw);
};

class String
{

public:
	String();
	String(const String& other); // Copy
	String(String&& other); // Move

	String(const char* raw, int size);
	AE_UNSAFE String(const char* raw); // Unsafe
	
	~String();

public:
	void Set(const String& other);
	void Set(const char* raw, int size);
	void AE_UNSAFE Set(const char* raw);
	const char* Raw();
	void Append(String& other);
	void Clear();

public:
	String& operator=(const String& other);

private:
	Array<char> m_Arr;

};

}