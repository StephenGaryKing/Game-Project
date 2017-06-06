#include "Vector2.h"
#include <math.h>

//constructor
Vector2::Vector2()
{

}
Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

//comparison operators
bool Vector2::operator == (Vector2 &other)
{
	return x == other.x && y == other.y;
}

bool Vector2::operator != (Vector2 &other)
{
	return x != other.x && y != other.y;
}

//Plus operators
Vector2 Vector2::operator + (float other)
{
	Vector2 newVector;
	newVector.x = x + other;
	newVector.y = y + other;
	return newVector;
}

Vector2 Vector2::operator + (const Vector2& other)
{
	Vector2 newVector;
	newVector.x = x + other.x;
	newVector.y = y + other.y;
	return newVector;
}

Vector2* Vector2::operator += (float other)
{
	x += other;
	y += other;
	return this;
}

//Minus operators
Vector2 Vector2::operator - (float other)
{
	Vector2 newVector;
	newVector.x = x - other;
	newVector.y = y - other;
	return newVector;
}

Vector2 Vector2::operator - (const Vector2& other)
{
	Vector2 newVector;
	newVector.x = x - other.x;
	newVector.y = y - other.y;
	return newVector;
}

Vector2* Vector2::operator -= (float other)
{
	x -= other;
	y -= other;
	return this;
}

//multiplication
Vector2 operator * (float lhs, Vector2 rhs)
{
	Vector2 newVector;
	newVector = rhs * lhs;
	return newVector;
}

Vector2 Vector2::operator * (float other)
{
	Vector2 newVector;
	newVector.x = x * other;
	newVector.y = y * other;
	return newVector;
}

Vector2 Vector2::operator * (const Vector2& other)
{
	Vector2 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	return newVector;
}

Vector2* Vector2::operator *= (float other)
{
	x *= other;
	y *= other;
	return this;
}

//division
Vector2 Vector2::operator / (float other)
{
	Vector2 newVector;
	newVector.x = x / other;
	newVector.y = y / other;
	return newVector;
}

Vector2 Vector2::operator / (const Vector2& other)
{
	Vector2 newVector;
	newVector.x = x / other.x;
	newVector.y = y / other.y;
	return newVector;
}

Vector2* Vector2::operator /= (float other)
{
	x /= other;
	y /= other;
	return this;
}

//other maths functions
float Vector2::dot(const Vector2 &other)
{
	Vector2 newVector;
	newVector.x = x * other.x;
	newVector.y = y * other.y;
	return newVector.x + newVector.y;
}

float Vector2::GetMagnitude()
{
	return sqrtf(x* x + y* y);
}

float Vector2::magnitude()
{
	return GetMagnitude();
}

Vector2 Vector2::GetNormalised()
{
	Vector2 newVector;
	float magnitude = GetMagnitude();
	newVector.x = x / magnitude;
	newVector.y = y / magnitude;
	return newVector;
}

void Vector2::normalise()
{
	float magnitude = GetMagnitude();
	x = x / magnitude;
	y = y / magnitude;
}

void Vector2::ClampInBox(Vector2 min, Vector2 max)
{
	if (x < min.x)
		x = min.x;
	if (y < min.y)
		y = min.y;
	if (x > max.x)
		x = max.x;
	if (y > max.y)
		y = max.y;
}

void Vector2::SetRotate(float angle)
{
	x = cosf(angle) - sinf(angle);
	y = sinf(angle) + cosf(angle);
}

void Vector2::Rotate(float angle)
{
	x = x * cosf(angle) - y * sinf(angle);
	y = x * sinf(angle) + y * cosf(angle);
}

Vector2::operator float*()
{
	return &x;
}

//deconstructor
Vector2::~Vector2()
{
}
