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
String::String()
{
}

String::String(const String& other)
{
	Set(other);
}

String::String(String&& other)
{
	Set(other);
	other.Clear();
}

String::String(std::initializer_list<char> elements)
{
	m_Arr.Push(elements);
}

String::String(const char* raw)
{
	Set(raw);
}

String::String(const char* raw, unsigned int size)
{
	Set(raw, size);
}

String::~String()
{
}

void String::Set(const String& other)
{
	m_Arr = other.m_Arr;
}

void String::Set(const char* raw, unsigned int size)
{
	// Clear the string
	Clear();

	size++; // Add the null terminator.
	m_Arr.Resize(size);
	for (unsigned int i = 0; i < size; i++)
		m_Arr.Push((char)raw[i]);
}

void String::Set(const char* raw)
{
	Set(raw, StringRawUtils::Size(raw));
}

void String::Clear()
{
	m_Arr.Clear();
}

const char* String::Raw() const
{
	return m_Arr.Raw();
}

unsigned int String::Size() const
{
	return m_Arr.Count();
}

}