#pragma once

#include <initializer_list>
#include <memory.h>

namespace AE
{

template <typename T>
class Array
{
	
public:
	Array(); // Default
	Array(const Array& other); // Copy
	Array(Array&& other) // Move

	Array(const T* raw, int count);
	Array(std::initializer_list<T> elements);

	~Array();

public:
	void 	Resize(int newCapacity);
	void 	Add(T&& elem);
	void 	Add(std::initializer_list<T> elements);
	void 	Remove(int index);
	void 	Insert(T& elem, int index);
	void 	Clear();
	T&		Get(int index);
	int		Count();
	int		Capacity();
	T*		Raw();

private:
	T* m_Raw;
	unsigned m_Capacity;
	unsigned m_Count;
};

template <typename T>
Array::Array()
{
	Resize(5);
}

template <typename T>
Array::Array(const Array<T>& other)
{
	Resize(other.Capacity());
	memcpy(m_Raw, other.GetRaw(), sizeof(T) * other.Capacity());
	m_Count = other.Count();
}



}