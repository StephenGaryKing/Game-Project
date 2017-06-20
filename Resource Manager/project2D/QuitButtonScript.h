#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "GameStateManager.h"

class QuitButtonScript
	: public Component
{
public:
	QuitButtonScript()
	{
		m_componentType = ComponentType::SCRIPT;
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new QuitButtonScript(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	GameStateManager*		m_gameStateManager;

};