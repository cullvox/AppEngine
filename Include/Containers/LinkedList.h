#pragma once

namespace AE
{

template <typename T>
class LinkedList
{

public:
	struct LinkedListElement
	{
		T value;
		LinkedListElement* next;
		LinkedListElement* prev;
	};

public:
	LinkedList(); // Default
	LinkedList(const LinkedList& other); // Copy
	LinkedList(const LinkedList&& other); // Move
	~LinkedList();

public:
	void Push(T& value);
	void Pop();
	T& Front() const;
	T& Back() const;
	unsigned int Count() const;
	bool Empty() const;


public:
	LinkedListElement* m_Head;
	LinkedListElement* m_Last;
	unsigned int m_Count;

};

}

#include "LinkedList.inl"