#include "Math/Vector.h"

namespace AE
{

Vector2f::Vector2f()
{
    x = y = 0.f;
}

Vector2f::Vector2f(float xy)
{
    x = y = xy;
}

Vector2f::Vector2f(float _x, float _y)
{
    x = _x;
    y = _y;
}

Vector2f::~Vector2f()
{
}

Vector2f Vector2f::Add(const Vector2f& other) const
{
    return Vector2f(x + other.x, y + other.y);
}

Vector2f Vector2f::Sub(const Vector2f& other) const
{
    return Vector2f(x - other.x, y - other.y);
}

Vector2f Vector2f::Mul(const Vector2f& other) const
{
    return Vector2f(x * other.x, y * other.y);
}

Vector2f Vector2f::Div(const Vector2f& other) const
{
    return Vector2f(x / other.x, y / other.y);
}

Vector2f Vector2f::operator+(const Vector2f& other) const
{
    return Add(other);
}

Vector2f Vector2f::operator-(const Vector2f& other) const
{
    return Sub(other);
}

Vector2f Vector2f::operator*(const Vector2f& other) const
{
    return Mul(other);
}

Vector2f Vector2f::operator/(const Vector2f& other) const
{
    return Div(other);
}


Vector3f::Vector3f()
{
    x = y = z = 0.f;
}

Vector3f::Vector3f(float xyz)
{
    x = y = z = xyz;
}

Vector3f::Vector3f(float _x, float _y, float _z)
{
    x = _x;
    x = _y;
    z = _z;
}

Vector3f::~Vector3f()
{

}

Vector3f Vector3f::Add(const Vector3f& other) const
{
    return Vector3f(x + other.x, y + other.y, z + other.z);
}

Vector3f Vector3f::Sub(const Vector3f& other) const
{
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f Vector3f::Mul(const Vector3f& other) const
{
    return Vector3f(x * other.x, y * other.y, z * other.z);
}

Vector3f Vector3f::Div(const Vector3f& other) const
{
    return Vector3f(x / other.x, y / other.y, z / other.z);
}

Vector3f Vector3f::operator+(const Vector3f& other) const
{
    return Add(other);
}

Vector3f Vector3f::operator-(const Vector3f& other) const
{
    return Sub(other);
}

Vector3f Vector3f::operator*(const Vector3f& other) const
{
    return Mul(other);
}

Vector3f Vector3f::operator/(const Vector3f& other) const
{
    return Div(other);
}

Vector4f::Vector4f()
{
    x = y = z = w = 0.f;
}

Vector4f::Vector4f(const Vector4f& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

Vector4f::Vector4f(Vector4f&& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    other.x = other.y = other.z = other.w = 0.f;
}

Vector4f::Vector4f(float xyzw)
{
    x = y = z = w = xyzw;
}

Vector4f::Vector4f(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

Vector4f::~Vector4f()
{
}

Vector4f Vector4f::Add(const Vector4f& other) const
{
    return Vector4f(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4f Vector4f::Sub(const Vector4f& other) const
{
    return Vector4f(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4f Vector4f::Mul(const Vector4f& other) const
{
    return Vector4f(x * other.x, y * other.y, z * other.z, w * other.w);
}

Vector4f Vector4f::Div(const Vector4f& other) const
{
    return Vector4f(x / other.x, y / other.y, z / other.z, w / other.w);
}

Vector4f Vector4f::operator+(const Vector4f& other) const
{
    return Add(other);
}

Vector4f Vector4f::operator-(const Vector4f& other) const
{
    return Sub(other);
}

Vector4f Vector4f::operator*(const Vector4f& other) const
{
    return Mul(other);
}

Vector4f Vector4f::operator/(const Vector4f& other) const
{
    return Div(other);
}

}