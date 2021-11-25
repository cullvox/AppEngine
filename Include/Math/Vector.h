#pragma once

// Vector.h
// Contains simple mathematical vector 

namespace AE
{

struct Vector2f
{
	
public:
	Vector2f(); // Default
	Vector2f(const Vector2f& other) = default; // Copy
	Vector2f(Vector2f&& other) = default; // Move

	Vector2f(float xy);
	Vector2f(float x, float y);

	~Vector2f();

public:
	Vector2f Add(const Vector2f& other) const;
	Vector2f Sub(const Vector2f& other) const;
	Vector2f Mul(const Vector2f& other) const;
	Vector2f Div(const Vector2f& other) const;

public:
	Vector2f operator+(const Vector2f& other) const;
	Vector2f operator-(const Vector2f& other) const;
	Vector2f operator*(const Vector2f& other) const;
	Vector2f operator/(const Vector2f& other) const;

public:
	float x, y;

};

struct Vector3f
{
	
public:
	Vector3f(); // Default
	Vector3f(const Vector3f& other) = default; // Copy
	Vector3f(Vector3f&& other) = default; // Move

	Vector3f(float xyz);
	Vector3f(float x, float y, float z);

	~Vector3f();

public:
	Vector3f Add(const Vector3f& other) const;
	Vector3f Sub(const Vector3f& other) const;
	Vector3f Mul(const Vector3f& other) const;
	Vector3f Div(const Vector3f& other) const;

public:
	Vector3f operator+(const Vector3f& other) const;
	Vector3f operator-(const Vector3f& other) const;
	Vector3f operator*(const Vector3f& other) const;
	Vector3f operator/(const Vector3f& other) const;

public:
	float x, y, z;

};

struct Vector4f
{

public:
	Vector4f();
	Vector4f(const Vector4f& other);
	Vector4f(Vector4f&& other);

	Vector4f(float xyzw);
	Vector4f(float x, float y, float z, float w);

	~Vector4f();

public:
	Vector4f Add(const Vector4f& other) const;
	Vector4f Sub(const Vector4f& other) const;
	Vector4f Mul(const Vector4f& other) const;
	Vector4f Div(const Vector4f& other) const;

public:
	Vector4f operator+(const Vector4f& other) const;
	Vector4f operator-(const Vector4f& other) const;
	Vector4f operator*(const Vector4f& other) const;
	Vector4f operator/(const Vector4f& other) const;

public:
	float x, y, z, w;	

};

}