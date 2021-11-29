#pragma once

#include "NonCopyable.h"

namespace AE
{

template<typename T>
class TUniquePointer : public virtual INonCopyable
{

public:
	TUniquePointer();
	TUniquePointer(T* ptr);
	TUniquePointer(TUniquePointer&& other);
	~TUniquePointer();

public:
	TUniquePointer& operator=(TUniquePointer&& other); // Move

public:
	T* Release();

private:
	bool bReleased;
	T* m_Ptr;

};

}

#include "UniquePointer.inl"