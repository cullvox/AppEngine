#pragma once

template <typename T, int count>
struct VectorBase
{
	VectorBase();
	VectorBase();
	VectorBase();
	
};

struct Vector3f : VectorBase<T, 3>
{
	
public:
	Vector3(); // Default
	Vector3(); // Copy
	Vector3(); // Move

	Vector3(float xyz);
	Vector3(float x, float y, float z);

	~Vector3();

public:
	float x, y, z;

};