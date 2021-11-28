#pragma once

#include "Math/Vector.h"
#include "Quaternion.h"

namespace AE
{

struct SMatrix4f
{

public:
	SMatrix4f(); // Default
	SMatrix4f(const SMatrix4f& other); // Copy
	SMatrix4f(SMatrix4f&& other); // Move

	SMatrix4f(float raw[16]);

public:
	static SMatrix4f Identity();

public:
	SMatrix4f Add(const SMatrix4f& other) const;
	SMatrix4f Sub(const SMatrix4f& other) const;
	SMatrix4f Mul(const SMatrix4f& other) const;

public:
	SMatrix4f& Translate(const Vector3f& position);
	SMatrix4f& TranslateTo(const Vector3f& position);
	SMatrix4f& Rotate(const Quaternion& rotation);
	SMatrix4f& RotateTo(const Quaternion& rotation); // Not implemented
	SMatrix4f& RotateX(const float angle);
	SMatrix4f& RotateY(const float angle);
	SMatrix4f& RotateZ(const float angle);
	SMatrix4f& Rotate(const Vector3f& euler);
	SMatrix4f& RotateTo(const Vector3f& euler); // Not implemented
	SMatrix4f& LookAt(const Vector3f& position);
	SMatrix4f& Scale(const Vector3f& scale);
	SMatrix4f& ScaleTo(const Vector3f& scale);
	SMatrix4f& Scale(const float uniformScale);
	SMatrix4f& ScaleTo(const float uniformScale);

// Camera Frustrums
public:
	SMatrix4f& SetFrustrum(float left, float right, float bottom, float top, float near, float far);
	SMatrix4f& SetFrustrumPerspective(float fovY, float aspectRatio, float near, float far);
	SMatrix4f& SetFrustrumOrthographic(float left, float right, float bottom, float top, float near, float far);
	SMatrix4f& SetFrustrumIsometric();

public:
	float* Raw() const; // Returns float[16]

public:
	SMatrix4f operator+(const SMatrix4f& other) const;
	SMatrix4f operator-(const SMatrix4f& other) const;
	SMatrix4f operator*(const SMatrix4f& other) const;
	SMatrix4f operator=(const SMatrix4f& other);

private:
	float m_Raw[16];

};


}