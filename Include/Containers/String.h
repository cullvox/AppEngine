#pragma once

// String.h
// Contains C String helpers and cn abstraction class of a C string

#include <initializer_list>

#include "Array.h"

namespace AE
{

class StringRawUtils
{
public:
	static unsigned int Size(const char* raw, unsigned int max);
	static unsigned int Size(const char* raw);
};

class SString
{

public:
	SString();
	SString(const SString& other); // Copy
	SString(SString&& other); // Move

	SString(std::initializer_list<char> elements);
	SString(const char* raw); // MUST be a null-terminated string
	SString(const char* raw, unsigned int size);
	
	~SString();

public:
	void Set(const SString& other);
	void Set(const char* raw); // Must be a null-terminated string
	void Set(const char* raw, unsigned int size);
	void Clear();
	void Append(SString& other);
	const char* Raw() const;
	unsigned int Size() const;

public:
	// The string formatter only supports simple formatting tools
	// %i for int or longs, %f for float or double, %s for string, and %b for bool
	template <class...Types>
	static SString Format(const SString& format, Types...);

public:
	SString& operator=(const SString& other);
	SString& operator+(const SString& other);

private:
	TArray<char> m_Arr;

};

}

#include "String.inl"