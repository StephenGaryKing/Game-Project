#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Vector3.h"

class AsteroidScript
	: public Component
{
public:
	AsteroidScript()
	{
		m_componentType = ComponentType::SCRIPT;
		m_velocity = Vector3{ (float)(rand() % (m_maxSpeed - m_minSpeed)) + m_minSpeed, (float)(rand() % (m_maxSpeed - m_minSpeed) + m_minSpeed), 0.0f };
		m_velocity = m_velocity * Vector3{ (rand() % 2 == 0) ? 1.0f : -1.0f, (rand() % 2 == 0) ? 1.0f : -1.0f, 0.0f };
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	Vector3 m_velocity;
	int m_maxSpeed = 5;
	int m_minSpeed = 2;

};