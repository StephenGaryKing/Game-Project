#pragma once
#include "Component.h"
#include "ResourceManager.h"

class MouseInputComp
	: public Component
{
public:
	MouseInputComp()
	{
		m_componentType = ComponentType::INPUT;
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	float m_mouseX;
	float m_mouseY;
};