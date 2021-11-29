#include <string.h>

#include "Containers/String.h"

namespace AE
{

// UTILS
unsigned int StringRawUtils::Size(const char* raw, unsigned int MAX)
{
	return (unsigned int)strnlen(raw, MAX);
}

unsigned int StringRawUtils::Size(const char* raw)
{
	return (unsigned int)strlen(raw); // I don't think that this is a good idea.
}

// STRING
FString::FString()
{
}

FString::FString(const FString& other)
{
	Set(other);
}

FString::FString(FString&& other)
{
	Set(other);
	other.Clear();
}

FString::FString(std::initializer_list<char> elements)
{
	m_Arr.Push(elements);
}

FString::FString(const char* raw)
{
	Set(raw);
}

FString::FString(const char* raw, unsigned int size)
{
	Set(raw, size);
}

FString::~FString()
{
}

void FString::Set(const FString& other)
{
	m_Arr = other.m_Arr;
}

void FString::Set(const char* raw, unsigned int size)
{
	// Clear the string
	Clear();

	size++; // Add the null terminator.
	m_Arr.Resize(size);
	for (unsigned int i = 0; i < size; i++)
		m_Arr.Push((char)raw[i]);
}

void FString::Set(const char* raw)
{
	Set(raw, StringRawUtils::Size(raw));
}

void FString::Clear()
{
	m_Arr.Clear();
}

const char* FString::Raw() const
{
	return m_Arr.Raw();
}

unsigned int FString::Size() const
{
	return m_Arr.Count();
}

FString& FString::Append(const FString& other)
{
	unsigned int oldSize = Size();
	m_Arr.Resize(Size() + other.Size());

	for (unsigned int i = 0; i < other.Size(); i++)
	{
		m_Arr[i + oldSize] = other.Raw()[i];
	}
}

}