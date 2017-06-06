#include "Matrix4.h"
#include <math.h>

//constructor
Matrix4::Matrix4()
{
	matrix[0] = { 1, 0, 0, 0 };
	matrix[1] = { 0, 1, 0, 0 };
	matrix[2] = { 0, 0, 1, 0 };
	matrix[3] = { 0, 0, 0, 1 };
}

Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
{
	matrix[0] = { a, b, c, d };
	matrix[1] = { e, f, g, h };
	matrix[2] = { i, j, k, l };
	matrix[3] = { m, n, o, p };
}

//functions
void Matrix4::transpose()
{
	Vector4 tempMatrix[4] = { matrix[0], matrix[1], matrix[2], matrix[3] };
	matrix[0] = { tempMatrix[0].x, tempMatrix[1].x, tempMatrix[2].x, tempMatrix[3].x };
	matrix[1] = { tempMatrix[0].y, tempMatrix[1].y, tempMatrix[2].y, tempMatrix[3].y };
	matrix[2] = { tempMatrix[0].z, tempMatrix[1].z, tempMatrix[2].z, tempMatrix[3].z };
	matrix[3] = { tempMatrix[0].w, tempMatrix[1].w, tempMatrix[2].w, tempMatrix[3].w };

	matrix[0] = tempMatrix[0];
	matrix[1] = tempMatrix[1];
	matrix[2] = tempMatrix[2];
	matrix[3] = tempMatrix[3];
}

void Matrix4::setRotateX(float angle)
{
	matrix[1].y = cosf(angle);
	matrix[1].z = sinf(angle);
	matrix[2].y = -sinf(angle);
	matrix[2].z = cosf(angle);
}

void Matrix4::setRotateY(float angle)
{
	matrix[0].x = cosf(angle);
	matrix[2].x = sinf(angle);
	matrix[0].z = -sinf(angle);
	matrix[2].z = cosf(angle);
}

void Matrix4::setRotateZ(float angle)
{
	matrix[0].x = cosf(angle);
	matrix[0].y = sinf(angle);
	matrix[1].x = -sinf(angle);
	matrix[1].y = cosf(angle);
}

//operators
Vector4 Matrix4::operator * (Vector4 other)
{
	Vector4 newVector;
	newVector.x = other.dot({ matrix[0].x, matrix[1].x, matrix[2].x, matrix[3].x });
	newVector.y = other.dot({ matrix[0].y, matrix[1].y, matrix[2].y, matrix[3].y });
	newVector.z = other.dot({ matrix[0].z, matrix[1].z, matrix[2].z, matrix[3].z });
	newVector.w = other.dot({ matrix[0].w, matrix[1].w, matrix[2].w, matrix[3].w });
	return newVector;
}

Matrix4 Matrix4::operator * (Matrix4 other)
{
	Matrix4 newMatrix;
	newMatrix[0].x = other[0].dot({ matrix[0].x, matrix[1].x, matrix[2].x, matrix[3].x });
	newMatrix[0].y = other[0].dot({ matrix[0].y, matrix[1].y, matrix[2].y, matrix[3].y });
	newMatrix[0].z = other[0].dot({ matrix[0].z, matrix[1].z, matrix[2].z, matrix[3].z });
	newMatrix[0].w = other[0].dot({ matrix[0].w, matrix[1].w, matrix[2].w, matrix[3].w });
	newMatrix[1].x = other[1].dot({ matrix[0].x, matrix[1].x, matrix[2].x, matrix[3].x });
	newMatrix[1].y = other[1].dot({ matrix[0].y, matrix[1].y, matrix[2].y, matrix[3].y });
	newMatrix[1].z = other[1].dot({ matrix[0].z, matrix[1].z, matrix[2].z, matrix[3].z });
	newMatrix[1].w = other[0].dot({ matrix[0].w, matrix[1].w, matrix[2].w, matrix[3].w });
	newMatrix[2].x = other[2].dot({ matrix[0].x, matrix[1].x, matrix[2].x, matrix[3].x });
	newMatrix[2].y = other[2].dot({ matrix[0].y, matrix[1].y, matrix[2].y, matrix[3].y });
	newMatrix[2].z = other[2].dot({ matrix[0].z, matrix[1].z, matrix[2].z, matrix[3].z });
	newMatrix[2].w = other[0].dot({ matrix[0].w, matrix[1].w, matrix[2].w, matrix[3].w });
	return newMatrix;
}

Vector4& Matrix4::operator [] (int num)
{
	return matrix[num];
}

Matrix4::operator float*()
{
	return &matrix[0].x;
}

//deconstructor
Matrix4::~Matrix4()
{
}
