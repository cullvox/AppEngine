#include <memory.h>

namespace AE
{

template <typename T>
Array<T>::Array()
{
	Resize(5);
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	Resize(other.Capacity());
	memcpy(m_Raw, other.GetRaw(), sizeof(T) * other.Capacity());
	m_Count = other.Count();
}

template <typename T>
Array<T>::Array(const T* raw, unsigned int count)
{
	Resize(count);
	memcpy(m_Raw, raw, sizeof(T) * count);
	m_Count = count;
}
	
template <typename T>
Array<T>::Array(std::initializer_list<T> elements)
{
	Push(elements);
}

template <typename T>
Array<T>::~Array()
{
	if (m_Raw != nullptr)
		delete m_Raw;
}

template <typename T>
void Array<T>::Resize(unsigned int capacity)
{
	if (m_Capacity == capacity)
		return;

	// Allocate a new array and copy the old data over
	T* raw = new T[capacity];
	memcpy(raw, m_Raw, sizeof(T) * m_Count);
	
	// Delete the old array
	if (m_Raw)
		delete[] m_Raw;

	m_Raw = raw;
	m_Capacity = capacity;
	memset(m_Raw + m_Count, 0, sizeof(T) * (m_Capacity - m_Count));
}

template <typename T>
void Array<T>::Set(unsigned int index, T& value)
{
	m_Raw[index] = value;
}

template <typename T>
T& Array<T>::Get(unsigned int index)
{
	return m_Raw[index];
}

template <typename T>
void Array<T>::Remove(unsigned int index)
{
	memcpy(m_Raw[index], m_Raw[index] + 1, sizeof(T) * m_Count);
}

template <typename T>
void Array<T>::Push(T& value)
{
	// Check for resize 
	if (m_Count == m_Capacity)
	{
		Resize(m_Capacity + 1);
	}

	Set(m_Count, value);
	m_Count++;
}

template <typename T>
void Array<T>::Push(std::initializer_list<T> elements)
{
	typename std::initializer_list<T>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
	{
		Push((T&)*it);
	}
}

template <typename T>
void Array<T>::Pop()
{
	Remove(m_Count);
}

template <typename T>
void Array<T>::Clear()
{
	memset(m_Raw, 0, sizeof(T) * m_Capacity);
	m_Count = 0;
}

template <typename T>
T& Array<T>::First() const
{
	return Get(0);
}

template <typename T>
T& Array<T>::Last() const
{
	return Get(m_Count - 1);
}

template <typename T>
int Array<T>::Count() const
{
	return m_Count;
}

template <typename T>
int Array<T>::Capacity() const
{
	return m_Capacity;
}

template <typename T>
T* Array<T>::Raw() const
{
	return m_Raw;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) // Copy
{
	if (&other == this)
		return *this;

	Resize(other.Capacity());
	memcpy(m_Raw, other.m_Raw, sizeof(T) * other.Count());
	m_Count = other.Count();
	m_Capacity = other.Capacity();
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	return Get(index);
}

}