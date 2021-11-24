#pragma once

#include <initializer_list>

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

	String(std::initializer_list<char> elements);
	String(const char* raw); // MUST be a null-terminated string
	String(const char* raw, unsigned int size);
	
	~String();

public:
	void Set(const String& other);
	void Set(const char* raw); // Must be a null-terminated string
	void Set(const char* raw, unsigned int size);
	void Clear();
	void Append(String& other);
	const char* Raw() const;
	unsigned int Size() const;

public:
	String& operator=(const String& other);
	String& operator+(const String& other);

private:
	Array<char> m_Arr;

};

}