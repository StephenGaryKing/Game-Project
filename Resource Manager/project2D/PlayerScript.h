#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "GameStateManager.h"

class PlayerScript
	: public Component
{
public:
	PlayerScript()
	{
		m_componentType = ComponentType::SCRIPT;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new PlayerScript(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);
	
	GameStateManager*		m_gameStateManager;
};