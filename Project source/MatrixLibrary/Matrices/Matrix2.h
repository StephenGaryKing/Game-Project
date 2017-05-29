#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	//constructor
	Matrix2();
	Matrix2(float a, float b, float c, float d);
	//functions
	void transpose();
	void setRotate(float angle);
	//operators
	Vector2 operator * (Vector2 other);
	Matrix2 operator * (Matrix2 other);
	Vector2& operator [] (int num);
	operator float*();
	//deconstructor
	~Matrix2();

	//variables
private:
	Vector2 matrix[2];
};
