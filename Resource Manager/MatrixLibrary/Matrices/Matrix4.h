#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	//constructor
	Matrix4();
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	//functions
	void transpose();
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);
	//operators
	Vector4 operator * (Vector4 other);
	Matrix4 operator * (Matrix4 other);
	Vector4& operator [] (int num);
	operator float*();
	//deconstructor
	~Matrix4();

	//variables
private:
	Vector4 matrix[4];
};
