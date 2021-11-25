#pragma once

#include "Math/Vector.h"
#include "Quaternion.h"

namespace AE
{

struct Matrix4f
{

public:
	Matrix4f(); // Default
	Matrix4f(const Matrix4f& other); // Copy
	Matrix4f(Matrix4f&& other); // Move

	Matrix4f(float raw[16]);

public:
	static Matrix4f Identity();

public:
	Matrix4f Add(const Matrix4f& other) const;
	Matrix4f Sub(const Matrix4f& other) const;
	Matrix4f Mul(const Matrix4f& other) const;

public:
	Matrix4f& Translate(const Vector3f& position);
	Matrix4f& TranslateTo(const Vector3f& position);
	Matrix4f& Rotate(const Quaternion& rotation);
	Matrix4f& RotateTo(const Quaternion& rotation); // Not implemented
	Matrix4f& RotateX(const float angle);
	Matrix4f& RotateY(const float angle);
	Matrix4f& RotateZ(const float angle);
	Matrix4f& Rotate(const Vector3f& euler);
	Matrix4f& RotateTo(const Vector3f& euler); // Not implemented
	Matrix4f& LookAt(const Vector3f& position);
	Matrix4f& Scale(const Vector3f& scale);
	Matrix4f& ScaleTo(const Vector3f& scale);
	Matrix4f& Scale(const float uniformScale);
	Matrix4f& ScaleTo(const float uniformScale);

// Camera Frustrums
public:
	Matrix4f& SetFrustrum(float left, float right, float bottom, float top, float near, float far);
	Matrix4f& SetFrustrumPerspective(float fovY, float aspectRatio, float near, float far);
	Matrix4f& SetFrustrumOrthographic(float left, float right, float bottom, float top, float near, float far);
	Matrix4f& SetFrustrumIsometric();

public:
	float* Raw() const; // Returns float[16]

public:
	Matrix4f operator+(const Matrix4f& other) const;
	Matrix4f operator-(const Matrix4f& other) const;
	Matrix4f operator*(const Matrix4f& other) const;
	Matrix4f operator=(const Matrix4f& other);

private:
	float m_Raw[16];

};


}