#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	//constructor
	Matrix3();
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	//functions
	void transpose();
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);
	//operators
	Vector3 operator * (Vector3 other);
	Matrix3 operator * (Matrix3 other);
	Vector3& operator [] (int num);
	operator float*();
	//deconstructor
	~Matrix3();

	//variables
private:
	Vector3 matrix[3];
};
