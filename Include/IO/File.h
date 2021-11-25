#pragma once

#include "Containers/String.h"

class File
{

public:
    File();
    File(const String& path);
    
    ~File();

public:
    void Rename(const String& newPath);
    unsigned int Size() const;
    

public:
    template<typename T>
    Read(T* buffer, unsigned int count);
    
    template<typename T>
    Write(T* buffer, unsigned int count);

}
