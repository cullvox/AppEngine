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
SString::SString()
{
}

SString::SString(const SString& other)
{
	Set(other);
}

SString::SString(SString&& other)
{
	Set(other);
	other.Clear();
}

SString::SString(std::initializer_list<char> elements)
{
	m_Arr.Push(elements);
}

SString::SString(const char* raw)
{
	Set(raw);
}

SString::SString(const char* raw, unsigned int size)
{
	Set(raw, size);
}

SString::~SString()
{
}

void SString::Set(const SString& other)
{
	m_Arr = other.m_Arr;
}

void SString::Set(const char* raw, unsigned int size)
{
	// Clear the string
	Clear();

	size++; // Add the null terminator.
	m_Arr.Resize(size);
	for (unsigned int i = 0; i < size; i++)
		m_Arr.Push((char)raw[i]);
}

void SString::Set(const char* raw)
{
	Set(raw, StringRawUtils::Size(raw));
}

void SString::Clear()
{
	m_Arr.Clear();
}

const char* SString::Raw() const
{
	return m_Arr.Raw();
}

unsigned int SString::Size() const
{
	return m_Arr.Count();
}

}