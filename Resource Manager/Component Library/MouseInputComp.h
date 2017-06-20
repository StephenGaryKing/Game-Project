#pragma once
#include "Component.h"
#include "ResourceManager.h"

class MouseInputComp
	: public Component
{
public:
	MouseInputComp()
	{
		m_componentType = ComponentType::MOUSEINPUT;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new MouseInputComp(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	float m_mouseX;
	float m_mouseY;
	bool m_mouseDown[3];
	bool m_mouseClicked[3];
};