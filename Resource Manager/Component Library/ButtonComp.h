#pragma once
#include "Component.h"
#include "ResourceManager.h"

class ButtonComp
	: public Component
{
public:
	ButtonComp()
	{
		m_componentType = ComponentType::BUTTON;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new ButtonComp(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	bool m_clicked = false;
};