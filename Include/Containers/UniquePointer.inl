namespace AE
{

template <typename T>
TUniquePointer<T>::TUniquePointer()
{
}

template <typename T>
TUniquePointer<T>::TUniquePointer(T* ptr)
{
	m_Ptr = ptr;
}

template <typename T>
TUniquePointer<T>::TUniquePointer(TUniquePointer&& other)
{
	bReleased = false;
	m_Ptr = other.Release();
}

template <typename T>
TUniquePointer<T>::~TUniquePointer()
{
	if (!bReleased)
	{
		delete m_Ptr;
	}
}

template <typename T>
TUniquePointer<T>& TUniquePointer<T>::operator=(TUniquePointer<T>&& other)
{
	other.Release();
	other.m_Ptr = nullptr;
	return *this;
}

template <typename T>
T* TUniquePointer<T>::Release()
{
	bReleased = true;
	return m_Ptr;
}

}