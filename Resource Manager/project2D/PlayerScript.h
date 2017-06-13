#pragma once
#include "Component.h"
#include "ResourceManager.h"

class PlayerScript
	: public Component
{
public:
	PlayerScript()
	{
		m_componentType = ComponentType::SCRIPT;
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);
	
};