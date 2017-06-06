#pragma once


class Vector3
{
public:
	//constructor
	Vector3();
	Vector3(float X, float Y, float Z);
	//functions
	float dot(const Vector3& other);
	Vector3 cross(const Vector3 &other);
	float magnitude();
	float GetMagnitude();
	void normalise();
	Vector3 GetNormalised();
	void ClampInBox(Vector3 min, Vector3 max);
	void SetRotate(float angle);
	void Rotate(float angle);
	//operators
	bool operator == (Vector3 &other);
	bool operator != (Vector3 &other);
	Vector3 operator + (float other);
	Vector3 operator + (const Vector3& other);
	Vector3* operator += (float other);
	Vector3 operator - (float other);
	Vector3 operator - (const Vector3& other);
	Vector3* operator -= (float other);
	friend Vector3 operator * (float lhs, Vector3 rhs);
	Vector3 operator * (float other);
	Vector3 operator * (const Vector3& other);
	Vector3* operator *= (float other);
	Vector3 operator / (float other);
	Vector3 operator / (const Vector3& other);
	Vector3* operator /= (float other);
	operator float*();
	//deconstructor
	~Vector3();
	//variables
	float x, y, z;
};