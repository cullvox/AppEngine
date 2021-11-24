#pragma once

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
	Matrix4f Add(const Matrix4f& other) const;
	Matrix4f Sub(const Matrix4f& other) const;
	Matrix4f Mul(const Matrix4f& other) const;

public:
	void Translate(const Vector3f& position);
	void TranslateTo(const Vector3f& position);
	void Rotate(const Quaternion& rotation);
	void RotateTo(const Quaternion& rotation);
	void Scale(const Vector3f& scale);
	void ScaleTo(const Vector3f& scale);

public:
	void PerspectiveProjection();
	void OrthographicProjection();
	void IsometricProjection();

private:
	float m_Raw[16];

};


}