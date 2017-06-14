#pragma once
#include "Input.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "Renderer2D.h"
#include <list>
#include <memory>

class GameState {
	friend class GameStateManager;
public:
	GameState() {}
	virtual ~GameState() {}
	bool isActive() const { return m_active; }

protected:

	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw() = 0;

	void enter() { m_active = true; onEnter(); }
	void exit() { m_active = false; onExit(); }

	// can be overwritten in derived classes that need to behave 
	// in certain ways when activated/deactivated or pushed/popped

	virtual void onEnter() {}
	virtual void onExit() {}
	virtual void onPushed() {}
	virtual void onPopped() {}

protected:
	aie::Input*			m_input;
	aie::Renderer2D*	m_renderer;
	std::shared_ptr<GameObjectFactory> m_gameObjectFactory;
	std::list<std::shared_ptr<GameObject>>	m_gameObjects;
	GameStateManager* m_gameStateManager;
	bool m_active = false;
};

