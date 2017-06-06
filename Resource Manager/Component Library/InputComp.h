#pragma once
#include "Component.h"
#include "ResourceManager.h"

class InputComp
	: public Component
{
public:
	InputComp()
	{
		m_componentType = ComponentType::INPUT;
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	int m_mouseX;
	int m_mouseY;
};