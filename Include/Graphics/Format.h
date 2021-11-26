#pragma once

// Format.h
// Contains formats that can be used in vertex attributes and textures

namespace AE
{

enum Format
{
    eR8,
    eR8G8,
    eR8G8B8,
    eR8G8B8A8,
    eR32,
    eR32G32,
    eR32G32B32,
    eR32G32B32A32,

    eR8G8B8_SRGB,
    eR8G8B8A8_SRGB,

};

// In bytes
static inline unsigned int GetFormatSize(Format format)
{
    switch (format)
    {
        case eR8:
            return 1;
        
        case eR8G8:
            return 2;
        
        case eR8G8B8:
            return 3;
        
        case eR8G8B8A8:
            return 4;

        case eR32:
            return 4;

        case eR32G32:
            return 8;
        
        case eR32G32B32:
            return 12;
        
        case eR32G32B32A32:
            return 16;

        case eR8G8B8_SRGB:
            return 3;
        
        case eR8G8B8A8_SRGB:
            return 4;
    
    default:
        return 0;
    }
}

}