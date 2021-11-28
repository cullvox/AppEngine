#include "cblas.h"

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

Vector3f Vector3f::Right()
{
    return Vector3f(1, 0, 0);
}

Vector3f Vector3f::Up()
{
    return Vector3f(0, 1, 0);
}

Vector3f Vector3f::Forward()
{
    return Vector3f(0, 0, 1);
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

Vector3f Vector3f::Cross(const Vector3f& other) const
{
    return Vector3f((y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x));
}

float Vector3f::Dot() const
{
    float xyz[3] = {x, y, z};
    return cblas_sdot(3, xyz, 0, nullptr, 0);
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

SVector4f::SVector4f()
{
    x = y = z = w = 0.f;
}

SVector4f::SVector4f(const SVector4f& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

SVector4f::SVector4f(SVector4f&& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    other.x = other.y = other.z = other.w = 0.f;
}

SVector4f::SVector4f(float xyzw)
{
    x = y = z = w = xyzw;
}

SVector4f::SVector4f(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

SVector4f::~SVector4f()
{
}

SVector4f SVector4f::Add(const SVector4f& other) const
{
    return SVector4f(x + other.x, y + other.y, z + other.z, w + other.w);
}

SVector4f SVector4f::Sub(const SVector4f& other) const
{
    return SVector4f(x - other.x, y - other.y, z - other.z, w - other.w);
}

SVector4f SVector4f::Mul(const SVector4f& other) const
{
    return SVector4f(x * other.x, y * other.y, z * other.z, w * other.w);
}

SVector4f SVector4f::Div(const SVector4f& other) const
{
    return SVector4f(x / other.x, y / other.y, z / other.z, w / other.w);
}

SVector4f SVector4f::operator+(const SVector4f& other) const
{
    return Add(other);
}

SVector4f SVector4f::operator-(const SVector4f& other) const
{
    return Sub(other);
}

SVector4f SVector4f::operator*(const SVector4f& other) const
{
    return Mul(other);
}

SVector4f SVector4f::operator/(const SVector4f& other) const
{
    return Div(other);
}

}