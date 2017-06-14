#pragma once
#include <memory>

// forward declare GameObject 
class GameObject;

enum ComponentType
{
	TRANSFORM = 0,
	TEXTURE,
	INPUT,
	ANIMATION,
	SCRIPT
};

class Component
{
public:
	virtual ~Component() {};

	virtual void update(GameObject* gameObject, float deltaTime) = 0;

	virtual void draw(GameObject* gameObject) {}

	ComponentType m_componentType;
};

typedef std::shared_ptr<Component> ComponentPtr;
