namespace AE
{

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	LinkedListElement* element = other.m_Head;
	for (unsigned int c = 0; c < other.Count(); c++)
	{
		Push(element->value);
		element = element->next;
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>&& other)
{
	m_Head = other.m_Head;
	m_Last = other.m_Last;
	m_Count = other.m_Count;
	other.m_Head = other.m_Last = nullptr;
	other.m_Count = 0;
}

template <typename T>
void LinkedList<T>::Push(T& value)
{
	// Create new element
	LinkedListElement* element = new LinkedListElement();
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
void LinkedList<T>::Pop()
{

	// Check the head
	if (m_Head == nullptr)
	{
		return;
	}

	LinkedListElement* element = m_Head;

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
T& LinkedList<T>::Front() const
{
	return m_Head->value;
}

template <typename T>
T& LinkedList<T>::Back() const
{
	return m_Last->value;
}

template <typename T>
unsigned int LinkedList<T>::Count() const
{
	return m_Count;
}

template <typename T>
bool LinkedList<T>::Empty() const
{
	return m_Count == 0;
}

}