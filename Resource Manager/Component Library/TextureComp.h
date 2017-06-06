#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Texture.h"

class TextureComp
	: public Component
{
public:
	TextureComp(const char* filename)
	{
		m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
		m_componentType = ComponentType::TEXTURE;
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	std::shared_ptr<ResourceBase> m_texture;

};