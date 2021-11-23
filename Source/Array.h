#pragma once

// Array.h
// Contains a simple cpp abstraction for a raw C array

#include <initializer_list>

namespace AE
{

template <typename T>
class Array
{
	
public:
	Array(); // Default
	Array(const Array& other); // Copy
	Array(Array&& other); // Move

	Array(const T* raw, int count);
	Array(std::initializer_list<T> elements);

	~Array();

public:
	void Resize(int capacity);
	void Set(int index, T& value);
	T& Get(int index);
	void Remove(int index);
	void Push(T& value);
	void Push(std::initializer_list<T> elements);
	void Pop();
	void Clear();
	T& First();
	T& Last();
	int Count();
	int Capacity();
	T* Raw();

private:
	T* m_Raw;
	unsigned m_Capacity;
	unsigned m_Count;
};

}

#include "Array.inl"