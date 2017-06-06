#include "Matrix2.h"
#include <math.h>

//constructor
Matrix2::Matrix2()
{
	matrix[0] = { 1, 0};
	matrix[1] = { 0, 1};
}

Matrix2::Matrix2(float a, float b, float c, float d)
{
	matrix[0] = { a, b };
	matrix[1] = { c, d };
}

//functions
void Matrix2::transpose()
{
	Vector2 tempMatrix[2] = { matrix[0], matrix[1]};
	matrix[0] = { tempMatrix[0].x, tempMatrix[1].x };
	matrix[1] = { tempMatrix[0].y, tempMatrix[1].y };

	matrix[0] = tempMatrix[0];
	matrix[1] = tempMatrix[1];
	matrix[2] = tempMatrix[2];
}

void Matrix2::setRotate(float angle)
{
	matrix[0].x = cosf(angle);
	matrix[0].y = sinf(angle);
	matrix[1].x = -sinf(angle);
	matrix[1].y = cosf(angle);
}

//operators
Vector2 Matrix2::operator * (Vector2 other)
{
	Vector2 newVector;
	newVector.x = other.dot({ matrix[0].x, matrix[1].x });
	newVector.y = other.dot({ matrix[0].y, matrix[1].y });
	return newVector;
}

Matrix2 Matrix2::operator * (Matrix2 other)
{
	Matrix2 newMatrix;
	newMatrix[0].x = other[0].dot({ matrix[0].x, matrix[1].x });
	newMatrix[0].y = other[0].dot({ matrix[0].y, matrix[1].y });
	newMatrix[1].x = other[1].dot({ matrix[0].x, matrix[1].x });
	newMatrix[1].y = other[1].dot({ matrix[0].y, matrix[1].y });
	return newMatrix;
}

Vector2& Matrix2::operator [] (int num)
{
	return matrix[num];
}

Matrix2::operator float*()
{
	return &matrix[0].x;
}

//deconstructor
Matrix2::~Matrix2()
{
}
