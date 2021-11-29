#pragma once

// LinkedList.h
// Contains a templated linked list implementation

namespace AE
{

template <typename T>
class TLinkedList
{

public:
	struct SLinkedListElement
	{
		T value;
		SLinkedListElement* next;
		SLinkedListElement* prev;
	};

public:
	TLinkedList(); // Default
	TLinkedList(const TLinkedList& other); // Copy
	~TLinkedList();

public:
	void Push(T& value);
	void Pop();
	T& Front() const;
	T& Back() const;
	unsigned int Count() const;
	bool Empty() const;
	void Clear();

public:
	SLinkedListElement* m_Head;
	SLinkedListElement* m_Last;
	unsigned int m_Count;

};

}

#include "LinkedList.inl"