#pragma once

namespace AE
{

class INonCopyable {

public:
    INonCopyable() = default;
    INonCopyable(const INonCopyable&) = delete;
    INonCopyable& operator=(const INonCopyable&) = delete;

};

}