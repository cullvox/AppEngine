#pragma once

struct Vector3f
{
	
public:
	Vector3f(); // Default
	Vector3f(const Vector3f& other); // Copy
	Vector3f(Vector3f&& other); // Move

	Vector3f(float xyz);
	Vector3f(float x, float y, float z);

	~Vector3f();

public:
	float x, y, z;

};