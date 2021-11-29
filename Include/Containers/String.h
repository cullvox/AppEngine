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

class FString
{

public:
	FString();
	FString(const FString& other); // Copy
	FString(FString&& other); // Move

	FString(std::initializer_list<char> elements);
	FString(const char* raw); // MUST be a null-terminated string
	FString(const char* raw, unsigned int size);
	
	~FString();

public:
	void Set(const FString& other);
	void Set(const char* raw); // Must be a null-terminated string
	void Set(const char* raw, unsigned int size);
	void Clear();
	FString& Append(const FString& other);
	const char* Raw() const;
	unsigned int Size() const;

	

public:
	// The string formatter only supports simple formatting tools
	// %i for int or longs, %f for float or double, %s for string, and %b for bool
	template <class...Types>
	static FString Format(const FString& format, Types...);

public:
	FString& operator=(const FString& other);
	FString& operator+(const FString& other);

private:
	TArray<char> m_Arr;

};

}

#include "String.inl"