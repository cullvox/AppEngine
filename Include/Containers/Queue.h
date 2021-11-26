#pragma once

// Queue.h
// A queue from a templated linked list

#include "LinkedList.h"

namespace AE
{

template <typename T>
using Queue = LinkedList<T>;

}