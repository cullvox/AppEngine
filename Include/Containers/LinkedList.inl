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

}