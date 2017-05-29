#include "Matrix3.h"
#include <math.h>

//constructor
Matrix3::Matrix3()
{
	matrix[0] = { 1, 0, 0 };
	matrix[1] = { 0, 1, 0 };
	matrix[2] = { 0, 0, 1 };
}

Matrix3::Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	matrix[0] = { a, b, c };
	matrix[1] = { d, e, f };
	matrix[2] = { g, h, i };
}

//functions
void Matrix3::transpose()
{
	Vector3 tempMatrix[3] = { matrix[0], matrix[1], matrix[2] };
	matrix[0] = { tempMatrix[0].x, tempMatrix[1].x, tempMatrix[2].x };
	matrix[1] = { tempMatrix[0].y, tempMatrix[1].y, tempMatrix[2].y };
	matrix[2] = { tempMatrix[0].z, tempMatrix[1].z, tempMatrix[2].z };

	matrix[0] = tempMatrix[0];
	matrix[1] = tempMatrix[1];
	matrix[2] = tempMatrix[2];
}

void Matrix3::setRotateX(float angle)
{
	matrix[1].y = cosf(angle);
	matrix[1].z = sinf(angle);
	matrix[2].y = -sinf(angle);
	matrix[2].z = cosf(angle);
}

void Matrix3::setRotateY(float angle)
{
	matrix[0].x = cosf(angle);
	matrix[2].x = sinf(angle);
	matrix[0].z = -sinf(angle);
	matrix[2].z = cosf(angle);
}

void Matrix3::setRotateZ(float angle)
{
	matrix[0].x = cosf(angle);
	matrix[0].y = sinf(angle);
	matrix[1].x = -sinf(angle);
	matrix[1].y = cosf(angle);
}

//operators
Vector3 Matrix3::operator * (Vector3 other)
{
	Vector3 newVector;
	newVector.x = other.dot({ matrix[0].x, matrix[1].x, matrix[2].x });
	newVector.y = other.dot({ matrix[0].y, matrix[1].y, matrix[2].y });
	newVector.z = other.dot({ matrix[0].z, matrix[1].z, matrix[2].z });
	return newVector;
}

Matrix3 Matrix3::operator * (Matrix3 other)
{
	Matrix3 newMatrix;
	newMatrix[0].x = other[0].dot({ matrix[0].x, matrix[1].x, matrix[2].x });
	newMatrix[0].y = other[0].dot({ matrix[0].y, matrix[1].y, matrix[2].y });
	newMatrix[0].z = other[0].dot({ matrix[0].z, matrix[1].z, matrix[2].z });
	newMatrix[1].x = other[1].dot({ matrix[0].x, matrix[1].x, matrix[2].x });
	newMatrix[1].y = other[1].dot({ matrix[0].y, matrix[1].y, matrix[2].y });
	newMatrix[1].z = other[1].dot({ matrix[0].z, matrix[1].z, matrix[2].z });
	newMatrix[2].x = other[2].dot({ matrix[0].x, matrix[1].x, matrix[2].x });
	newMatrix[2].y = other[2].dot({ matrix[0].y, matrix[1].y, matrix[2].y });
	newMatrix[2].z = other[2].dot({ matrix[0].z, matrix[1].z, matrix[2].z });
	return newMatrix;
}

Vector3& Matrix3::operator [] (int num)
{
	return matrix[num];
}

Matrix3::operator float*()
{
	return &matrix[0].x;
}

//deconstructor
Matrix3::~Matrix3()
{
}
