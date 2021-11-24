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
	T& First() const;
	T& Last() const;
	int Count() const;
	int Capacity() const; 
	T* Raw() const;

public:
	Array& operator=(const Array& other); // Copy

private:
	T* m_Raw = nullptr;
	unsigned m_Capacity = 0;
	unsigned m_Count = 0;
};

}

#include "Array.inl"