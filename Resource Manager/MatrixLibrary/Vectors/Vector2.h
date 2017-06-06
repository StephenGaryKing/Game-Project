#pragma once


class Vector2
{
public:
	//constructor
	Vector2();
	Vector2(float X, float Y);
	//functions
	float dot(const Vector2& other);
	float magnitude();
	float GetMagnitude();
	void normalise();
	Vector2 GetNormalised();
	void ClampInBox(Vector2 min, Vector2 max);
	void SetRotate(float angle);
	void Rotate(float angle);
	//operators
	bool operator == (Vector2 &other);
	bool operator != (Vector2 &other);
	Vector2 operator + (float other);
	Vector2 operator + (const Vector2& other);
	Vector2* operator += (float other);
	Vector2 operator - (float other);
	Vector2 operator - (const Vector2& other);
	Vector2* operator -= (float other);
	friend Vector2 operator * (float lhs, Vector2 rhs);
	Vector2 operator * (float other);
	Vector2 operator * (const Vector2& other);
	Vector2* operator *= (float other);
	Vector2 operator / (float other);
	Vector2 operator / (const Vector2& other);
	Vector2* operator /= (float other);
	operator float*();
	//deconstructor
	~Vector2();
	//variables
	float x, y;
};