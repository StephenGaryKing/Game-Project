#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "GameStateManager.h"

class MenuButtonScript
	: public Component
{
public:
	MenuButtonScript()
	{
		m_componentType = ComponentType::SCRIPT;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new MenuButtonScript(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	GameStateManager*		m_gameStateManager;

};