#include "Vector4.h"
#include <math.h>

Vector4::Vector4()
{

}
Vector4::Vector4(float X, float Y, float Z, float W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

//comparison operators
bool Vector4::operator == (Vector4 &other)
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4::operator != (Vector4 &other)
{
	return x != other.x && y != other.y && z != other.z && w != other.w;
}

//Plus operators
Vector4 Vector4::operator + (float other)
{
	Vector4 newVector;
	newVector.x = x + other;
	newVector.y = y + other;
	newVector.z = z + other;
	newVector.w = w + other;
	return newVector;
}

Vector4 Vector4::operator + (const Vector4& other)
{
	Vector4 newVector;
	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;
	newVector.w = w + other.w;
	return newVector;
}

Vector4* Vector4::operator += (float other)
{
	x += other;
	y += other;
	z += other;
	w += other;
	return this;
}

//Minus operators
Vector4 Vector4::operator - (float other)
{
	Vector4 newVector;
	newVector.x = x - other;
	newVector.y = y - other;
	newVector.z = z - other;
	newVector.w = w - other;
	return newVector;
}

Vector4 Vector4::operator - (const Vector4& other)
{
	Vector4 newVector;
	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;
	newVector.w = w - other.w;
	return newVector;
}

Vector4* Vector4::operator -= (float other)
{
	x -= other;
	y -= other;
	z -= other;
	w -= other;
	return this;
}

//multiplication
Vector4 operator * (float lhs, Vector4 rhs)
{
	Vector4 newVector;
	newVector = rhs * lhs;
	return newVector;
}

Vector4 Vector4::operator * (float other)
{
	Vector4 newVector;
	newVector.x = x * other;
	newVector.y = y * other;
	newVector.z = z * other;
	newVector.w = w * other;
	return newVector;
}

Vector4 Vector4::operator * (const Vector4& other)
{
	Vector4 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	newVector.z = z * other.z;
	newVector.w = w * other.w;
	return newVector;
}

Vector4* Vector4::operator *= (float other)
{
	x *= other;
	y *= other;
	z *= other;
	w *= other;
	return this;
}

//division
Vector4 Vector4::operator / (float other)
{
	Vector4 newVector;
	newVector.x = x / other;
	newVector.y = y / other;
	newVector.z = z / other;
	newVector.w = w / other;
	return newVector;
}

Vector4 Vector4::operator / (const Vector4& other)
{
	Vector4 newVector;
	newVector.x = x / other.x;
	newVector.y = y / other.y;
	newVector.z = z / other.z;
	newVector.w = w / other.w;
	return newVector;
}

Vector4* Vector4::operator /= (float other)
{
	x /= other;
	y /= other;
	z /= other;
	w /= other;
	return this;
}

//other maths functions
float Vector4::dot(const Vector4 &other)
{
	Vector4 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	newVector.z = z * other.z;
	newVector.w = w * other.w;
	return newVector.x + newVector.y + newVector.z + newVector.w;
}

Vector4 Vector4::cross(const Vector4 &other)
{
	Vector4 newVector;
	newVector.x = (y * other.z - z * other.y);
	newVector.y = (z * other.x - x * other.z);
	newVector.z = (x * other.y - y * other.x);
	newVector.w = 0;
	return newVector;
}

float Vector4::GetMagnitude()
{
	return sqrtf(x* x + y* y + z* z + w* w);
}

float Vector4::magnitude()
{
	return GetMagnitude();
}

Vector4 Vector4::GetNormalised()
{
	Vector4 newVector;
	float magnitude = GetMagnitude();
	newVector.x = x / magnitude;
	newVector.y = y / magnitude;
	newVector.z = z / magnitude;
	newVector.w = w / magnitude;
	return newVector;
}

void Vector4::normalise()
{
	float magnitude = GetMagnitude();
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
	w = w / magnitude;
}

Vector4::operator float*()
{
	return &x;
}

//deconstructor
Vector4::~Vector4()
{
}
