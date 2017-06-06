#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <list>
#include "ResourceManager.h"
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Resource.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	std::unique_ptr<GameObjectFactory>		m_gameObjectFactory;
	std::list<std::shared_ptr<GameObject>>	m_gameObjects;

	aie::Renderer2D*					m_2dRenderer;

	float m_cameraX, m_cameraY;
	float m_timer;
};