#pragma once

#include "Vector.h"

namespace AE
{

struct SMatrix4f;

struct Quaternion
{

public:
	Quaternion();
	Quaternion(const Quaternion& other); // Copy
	Quaternion(Quaternion&& other); // Move

	Quaternion(float xyzw);
	Quaternion(float x, float y, float z, float a);
	Quaternion(Vector3f euler);

public:
	Quaternion Add(const Quaternion& other);
	Quaternion Sub(const Quaternion& other);
	Quaternion Mul(const Quaternion& other);

public:
	void Rotate(float x, float y, float z, float a);
	void RotateTo(float x, float y, float z, float a);
	void RotateEuler(Vector3f euler);
	void RotateToEuler(Vector3f euler);

public:
	SMatrix4f ToMatrix();


public:
	float x, y, z, a;

};

};