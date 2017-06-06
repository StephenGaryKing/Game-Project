#pragma once


class Vector4
{
public:
	//constructor
	Vector4();
	Vector4(float X, float Y, float Z, float W);
	//functions
	float dot(const Vector4& other);
	Vector4 cross(const Vector4 &other);
	float magnitude();
	float GetMagnitude();
	void normalise();
	Vector4 GetNormalised();
	//operators
	bool operator == (Vector4 &other);
	bool operator != (Vector4 &other);
	Vector4 operator + (float other);
	Vector4 operator + (const Vector4& other);
	Vector4* operator += (float other);
	Vector4 operator - (float other);
	Vector4 operator - (const Vector4& other);
	Vector4* operator -= (float other);
	friend Vector4 operator * (float lhs, Vector4 rhs);
	Vector4 operator * (float other);
	Vector4 operator * (const Vector4& other);
	Vector4* operator *= (float other);
	Vector4 operator / (float other);
	Vector4 operator / (const Vector4& other);
	Vector4* operator /= (float other);
	operator float*();
	//deconstructor
	~Vector4();
	//variables
	float x, y, z, w;
};