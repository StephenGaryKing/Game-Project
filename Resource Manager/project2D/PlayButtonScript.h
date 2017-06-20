#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "GameStateManager.h"

class PlayButtonScript
	: public Component
{
public:
	PlayButtonScript()
	{
		m_componentType = ComponentType::SCRIPT;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new PlayButtonScript(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	GameStateManager*		m_gameStateManager;

};