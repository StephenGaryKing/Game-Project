#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Matrix3.h"

class TransformComp
	: public Component
{
public:
	TransformComp(Vector3 position, Vector3 rotation, float scale = 1)
		: m_position(position), m_rotation(rotation), m_scale(scale)
	{
		m_componentType = ComponentType::TRANSFORM;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr (new TransformComp(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	Matrix3 getTransform();

	Vector3 m_position;
	Vector3 m_rotation;
	float m_scale;
};