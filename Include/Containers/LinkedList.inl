namespace AE
{

template <typename T>
TLinkedList<T>::TLinkedList()
{
}

template <typename T>
TLinkedList<T>::TLinkedList(const TLinkedList<T>& other)
{
	SLinkedListElement* element = other.m_Head;
	for (unsigned int c = 0; c < other.Count(); c++)
	{
		Push(element->value);
		element = element->next;
	}
}

template <typename T>
TLinkedList<T>::~TLinkedList()
{
	Clear();
}

template <typename T>
void TLinkedList<T>::Push(T& value)
{
	// Create new element
	SLinkedListElement* element = new SLinkedListElement();
	element->value = value;
	element->next = nullptr;
	element->prev = m_Last;

	// Add to list
	if (m_Last != nullptr)
	{
		m_Last->next = element;
	}
	else
	{
		m_Head = element;
	}

	// Update last element
	m_Last = element;
	m_Count++;
}

template <typename T>
void TLinkedList<T>::Pop()
{

	// Check the head
	if (m_Head == nullptr)
	{
		return;
	}

	SLinkedListElement* element = m_Head;

	// Update head
	m_Head = m_Head->next;

	if (m_Head != nullptr)
	{
		m_Head->prev = nullptr;
	}
	else
	{
		m_Last = nullptr;
	}

	// Delete element
	delete element;
	m_Count--;
}

template <typename T>
T& TLinkedList<T>::Front() const
{
	return m_Head->value;
}

template <typename T>
T& TLinkedList<T>::Back() const
{
	return m_Last->value;
}

template <typename T>
unsigned int TLinkedList<T>::Count() const
{
	return m_Count;
}

template <typename T>
bool TLinkedList<T>::Empty() const
{
	return m_Count == 0;
}

template <typename T>
void TLinkedList<T>::Clear()
{
	for (unsigned int i = 0; i < Count(); i++)
		Pop();
}

}