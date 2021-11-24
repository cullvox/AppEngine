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
	return (unsigned int)strlen(raw); // This is really unsafe!
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

String::String(const char* raw, int size)
{
	Set(raw, size);
}

String::String(const char* raw)
{
	Set(raw, StringRawUtils::Size(raw));
}

}