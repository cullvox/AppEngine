#pragma once

// Array.h
// Contains a simple cpp abstraction for a raw C array

#include <initializer_list>

namespace AE
{

template <typename T>
class TArray
{
	
public:
	TArray(); // Default
	TArray(const TArray& other); // Copy

	TArray(const T* raw, unsigned int count);
	TArray(std::initializer_list<T> elements);

	~TArray();

public:
	void Resize(unsigned int capacity);
	void Set(unsigned int index, T& value);
	T& Get(unsigned int index) const;
	void Remove(unsigned int index);
	void Push(T& value);
	void Push(std::initializer_list<T> elements);
	void Pop();
	void Clear();
	T& First() const;
	T& Last() const;
	unsigned int Count() const;
	unsigned int Capacity() const; 
	T* Raw() const;

public:
	TArray& operator=(const TArray& other); // Copy
	T& operator[](unsigned int index) const;

private:
	T* m_Raw = nullptr;
	unsigned int m_Capacity = 0;
	unsigned int m_Count = 0;
};

}

#include "Array.inl"