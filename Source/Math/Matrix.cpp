#include <memory.h>
#include <math.h>

#include "cblas.h"

#include "Math/Geometry.h"
#include "Math/Matrix.h"

namespace AE
{

SMatrix4f::SMatrix4f()
{
	*this = Identity();
}

SMatrix4f::SMatrix4f(const SMatrix4f& other)
{
	memcpy(m_Raw, other.Raw(), sizeof(m_Raw));
}

SMatrix4f::SMatrix4f(SMatrix4f&& other)
{
	memmove(m_Raw, other.Raw(), sizeof(m_Raw));
}

SMatrix4f::SMatrix4f(float raw[16])
{
	memcpy(m_Raw, raw, sizeof(m_Raw));
}

SMatrix4f SMatrix4f::Identity()
{
	float identity[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	return SMatrix4f(identity);
}

SMatrix4f SMatrix4f::Add(const SMatrix4f& other) const
{
	SMatrix4f result;
	for (unsigned int i = 0; i < 16; i++)
	{
		result.m_Raw[i] = m_Raw[i] + other.m_Raw[i];
	}

	return result;
}

SMatrix4f SMatrix4f::Sub(const SMatrix4f& other) const
{
	SMatrix4f result;
	for (unsigned int i = 0; i < 16; i++)
	{
		result.m_Raw[i] = m_Raw[i] - other.m_Raw[i];
	}

	return result;
}

SMatrix4f SMatrix4f::Mul(const SMatrix4f& other) const
{
	SMatrix4f result;
	cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4, 4, 4, 1.0, m_Raw, 4, other.Raw(), 4, 0.0f, result.Raw(), 4);
	return result;
}

SMatrix4f& SMatrix4f::Translate(const Vector3f& position)
{
	m_Raw[3] += position.x;
	m_Raw[7] += position.y;
	m_Raw[11] += position.z;
	return *this;
}

SMatrix4f& SMatrix4f::TranslateTo(const Vector3f& position)
{
	m_Raw[3] = position.x;
	m_Raw[7] = position.y;
	m_Raw[11] = position.z;
	return *this;
}

SMatrix4f& SMatrix4f::Rotate(const Quaternion& rotation)
{
	// Stolen from http://www.songho.ca/opengl/gl_matrix.html
	// This could probably be simplified more for my requirements

	float c = cosf(rotation.a * DEGTORAD);    // cosine
    float s = sinf(rotation.a * DEGTORAD);    // sine
    float c1 = 1.0f - c;                // 1 - c
    float m0 = m_Raw[0],  m4 = m_Raw[4],  m8 = m_Raw[8],  m12= m_Raw[12],
          m1 = m_Raw[1],  m5 = m_Raw[5],  m9 = m_Raw[9],  m13= m_Raw[13],
          m2 = m_Raw[2],  m6 = m_Raw[6],  m10= m_Raw[10], m14= m_Raw[14]; // Build a Matrix3x4

    // build rotation matrix
    float r0 = rotation.x * rotation.x * c1 + c;
    float r1 = rotation.x * rotation.y * c1 + rotation.z * s;
    float r2 = rotation.x * rotation.z * c1 - rotation.y * s;
    float r4 = rotation.x * rotation.y * c1 - rotation.z * s;
    float r5 = rotation.y * rotation.y * c1 + c;
    float r6 = rotation.y * rotation.z * c1 + rotation.x * s;
    float r8 = rotation.x * rotation.z * c1 + rotation.y * s;
    float r9 = rotation.y * rotation.z * c1 - rotation.x * s;
    float r10= rotation.z * rotation.z * c1 + c; // Apply the rotation

    // multiply rotation matrix
    m_Raw[0] = r0 * m0 + r4 * m1 + r8 * m2;
    m_Raw[1] = r1 * m0 + r5 * m1 + r9 * m2;
    m_Raw[2] = r2 * m0 + r6 * m1 + r10* m2;
    m_Raw[4] = r0 * m4 + r4 * m5 + r8 * m6;
    m_Raw[5] = r1 * m4 + r5 * m5 + r9 * m6;
    m_Raw[6] = r2 * m4 + r6 * m5 + r10* m6;
    m_Raw[8] = r0 * m8 + r4 * m9 + r8 * m10;
    m_Raw[9] = r1 * m8 + r5 * m9 + r9 * m10;
    m_Raw[10]= r2 * m8 + r6 * m9 + r10* m10;
    m_Raw[12]= r0 * m12+ r4 * m13+ r8 * m14;
    m_Raw[13]= r1 * m12+ r5 * m13+ r9 * m14;
    m_Raw[14]= r2 * m12+ r6 * m13+ r10* m14; // Multiply Matrix3x4 to Matrix4x4

    return *this;
}

SMatrix4f& SMatrix4f::RotateX(const float angle)
{
    float c = cosf(angle * DEGTORAD);
    float s = sinf(angle * DEGTORAD);
    float m1 = m_Raw[1],  m2 = m_Raw[2],
          m5 = m_Raw[5],  m6 = m_Raw[6],
          m9 = m_Raw[9],  m10= m_Raw[10],
          m13= m_Raw[13], m14= m_Raw[14];

    m_Raw[1] = m1 * c + m2 *-s;
    m_Raw[2] = m1 * s + m2 * c;
    m_Raw[5] = m5 * c + m6 *-s;
    m_Raw[6] = m5 * s + m6 * c;
    m_Raw[9] = m9 * c + m10*-s;
    m_Raw[10]= m9 * s + m10* c;
    m_Raw[13]= m13* c + m14*-s;
    m_Raw[14]= m13* s + m14* c;

    return *this;
}

SMatrix4f& SMatrix4f::RotateY(const float angle)
{
	float c = cosf(angle * DEGTORAD);
    float s = sinf(angle * DEGTORAD);
    float m0 = m_Raw[0],  m2 = m_Raw[2],
          m4 = m_Raw[4],  m6 = m_Raw[6],
          m8 = m_Raw[8],  m10= m_Raw[10],
          m12= m_Raw[12], m14= m_Raw[14];

    m_Raw[0] = m0 * c + m2 * s;
    m_Raw[2] = m0 *-s + m2 * c;
    m_Raw[4] = m4 * c + m6 * s;
    m_Raw[6] = m4 *-s + m6 * c;
    m_Raw[8] = m8 * c + m10* s;
    m_Raw[10]= m8 *-s + m10* c;
    m_Raw[12]= m12* c + m14* s;
    m_Raw[14]= m12*-s + m14* c;

    return *this;
}

SMatrix4f& SMatrix4f::RotateZ(const float angle)
{
    float c = cosf(angle * DEGTORAD);
    float s = sinf(angle * DEGTORAD);
    float m0 = m_Raw[0],  m1 = m_Raw[1],
          m4 = m_Raw[4],  m5 = m_Raw[5],
          m8 = m_Raw[8],  m9 = m_Raw[9],
          m12= m_Raw[12], m13= m_Raw[13];

    m_Raw[0] = m0 * c + m1 *-s;
    m_Raw[1] = m0 * s + m1 * c;
    m_Raw[4] = m4 * c + m5 *-s;
    m_Raw[5] = m4 * s + m5 * c;
    m_Raw[8] = m8 * c + m9 *-s;
    m_Raw[9] = m8 * s + m9 * c;
    m_Raw[12]= m12* c + m13*-s;
    m_Raw[13]= m12* s + m13* c;

	return *this;
}

SMatrix4f& SMatrix4f::Rotate(const Vector3f& euler)
{
	RotateX(euler.x);
	RotateY(euler.y);
	RotateZ(euler.z);
	return *this;
}

SMatrix4f& SMatrix4f::RotateTo(const Vector3f& euler)
{
	return *this;
}

SMatrix4f& SMatrix4f::LookAt(const Vector3f& target)
{
	Vector3f position (m_Raw[12], m_Raw[13], m_Raw[14]);
	Vector3f forward = target - position;
	forward.Normalize();

	Vector3f left = Vector3f::Up().Cross(forward);
	left.Normalize();

	Vector3f up = forward.Cross(left);
	up.Normalize();

	m_Raw[0] = left.x;
	m_Raw[1] = left.y;
	m_Raw[2] = left.z;
	m_Raw[4] = up.x;
	m_Raw[5] = up.y;
	m_Raw[6] = up.z;
	m_Raw[8] = forward.x;
	m_Raw[9] = forward.y;
	m_Raw[10]= forward.z;

	return *this;
}

SMatrix4f& SMatrix4f::Scale(const Vector3f& scale)
{
	m_Raw[0] *= scale.x;
	m_Raw[5] *= scale.y;
	m_Raw[10] *= scale.z;
	return *this;
}

SMatrix4f& SMatrix4f::ScaleTo(const Vector3f& scale)
{
	m_Raw[0] = scale.x;
	m_Raw[5] = scale.y;
	m_Raw[10] = scale.z;
	return *this;
}

SMatrix4f& SMatrix4f::Scale(const float uniformScale)
{
	m_Raw[0] *= uniformScale; 
	m_Raw[5] *= uniformScale;
	m_Raw[10] *= uniformScale;
	return *this;
}

SMatrix4f& SMatrix4f::ScaleTo(const float uniformScale)
{
	m_Raw[0] = m_Raw[5] = m_Raw[10] = uniformScale;
	return *this;
}

SMatrix4f SMatrix4f::operator+(const SMatrix4f& other) const
{
	return Add(other);
}

SMatrix4f SMatrix4f::operator-(const SMatrix4f& other) const
{
	return Sub(other);
}

SMatrix4f SMatrix4f::operator*(const SMatrix4f& other) const
{
	return Mul(other);
}

SMatrix4f SMatrix4f::operator=(const SMatrix4f& other)
{
	memcpy(m_Raw, other.Raw(), sizeof(m_Raw));
	return *this;
}

}