#include "TransformComp.h"

void TransformComp::update(GameObject* gameObject, float deltaTime)
{

}

void TransformComp::draw(GameObject* gameObject)
{

}

Matrix3 TransformComp::getTransform()
{
	Matrix3 transform;
	transform.setRotateX(m_rotation.x);
	transform.setRotateY(m_rotation.y);
	transform.setRotateZ(m_rotation.z);
	transform[2] = m_position;
	return transform;
}