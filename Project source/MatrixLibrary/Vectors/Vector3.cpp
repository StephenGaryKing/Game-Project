#include "Vector3.h"
#include <math.h>

//constructor
Vector3::Vector3()
{

}
Vector3::Vector3(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

//comparison operators
bool Vector3::operator == (Vector3 &other)
{
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator != (Vector3 &other)
{
	return x != other.x && y != other.y && z != other.z;
}

//Plus operators
Vector3 Vector3::operator + (float other)
{
	Vector3 newVector;
	newVector.x = x + other;
	newVector.y = y + other;
	newVector.z = z + other;
	return newVector;
}

Vector3 Vector3::operator + (const Vector3& other)
{
	Vector3 newVector;
	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;
	return newVector;
}

Vector3* Vector3::operator += (float other)
{
	x += other;
	y += other;
	z += other;
	return this;
}

//Minus operators
Vector3 Vector3::operator - (float other)
{
	Vector3 newVector;
	newVector.x = x - other;
	newVector.y = y - other;
	newVector.z = z - other;
	return newVector;
}

Vector3 Vector3::operator - (const Vector3& other)
{
	Vector3 newVector;
	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;
	return newVector;
}

Vector3* Vector3::operator -= (float other)
{
	x -= other;
	y -= other;
	z -= other;
	return this;
}

//multiplication
Vector3 operator * (float lhs, Vector3 rhs)
{
	Vector3 newVector;
	newVector = rhs * lhs;
	return newVector;
}

Vector3 Vector3::operator * (float other)
{
	Vector3 newVector;
	newVector.x = x * other;
	newVector.y = y * other;
	newVector.z = z * other;
	return newVector;
}

Vector3 Vector3::operator * (const Vector3& other)
{
	Vector3 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	newVector.z = z * other.z;
	return newVector;
}

Vector3* Vector3::operator *= (float other)
{
	x *= other;
	y *= other;
	z *= other;
	return this;
}

//division
Vector3 Vector3::operator / (float other)
{
	Vector3 newVector;
	newVector.x = x / other;
	newVector.y = y / other;
	newVector.z = z / other;
	return newVector;
}

Vector3 Vector3::operator / (const Vector3& other)
{
	Vector3 newVector;
	newVector.x = x / other.x;
	newVector.y = y / other.y;
	newVector.z = z / other.z;
	return newVector;
}

Vector3* Vector3::operator /= (float other)
{
	x /= other;
	y /= other;
	z /= other;
	return this;
}

//other maths functions
float Vector3::dot(const Vector3 &other)
{
	Vector3 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	newVector.z = z * other.z;
	return newVector.x + newVector.y + newVector.z;
}

Vector3 Vector3::cross(const Vector3 &other)
{
	Vector3 newVector;
	newVector.x = (y * other.z - z * other.y);
	newVector.y = (z * other.x - x * other.z);
	newVector.z = (x * other.y - y * other.x);
	return newVector;
}

float Vector3::GetMagnitude()
{
	return sqrtf(x* x + y* y + z* z);
}

float Vector3::magnitude()
{
	return GetMagnitude();
}

Vector3 Vector3::GetNormalised()
{
	Vector3 newVector;
	float magnitude = GetMagnitude();
	newVector.x = x / magnitude;
	newVector.y = y / magnitude;
	newVector.z = z / magnitude;
	return newVector;
}

void Vector3::normalise()
{
	float magnitude = GetMagnitude();
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
}

void Vector3::ClampInBox(Vector3 min, Vector3 max)
{
	if (x < min.x)
		x = min.x;
	if (y < min.y)
		y = min.y;
	if (z < min.z)
		z = min.z;
	if (x > max.x)
		x = max.x;
	if (y > max.y)
		y = max.y;
	if (z > max.z)
		z = max.z;
}

void Vector3::SetRotate(float angle)
{
	x = cosf(angle) - sinf(angle);
	y = sinf(angle) + cosf(angle);
}

void Vector3::Rotate(float angle)
{
	x = x * cosf(angle) - y * sinf(angle);
	y = x * sinf(angle) + y * cosf(angle);
}

Vector3::operator float*()
{
	return &x;
}

//deconstructor
Vector3::~Vector3()
{
}
