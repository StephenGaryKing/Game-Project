#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Input.h"
#include "ListOfStates.h"
class GameState
{
	friend class GameStateManager;
public:
	GameState() {}
	virtual ~GameState() {}

	bool isActive() const { return m_active; }

protected:
	virtual int onUpdate(aie::Input* input, float deltaTime) = 0;
	virtual void onDraw(aie::Renderer2D* renderer) = 0;

	void enter() { m_active = true; onEnter(); }
	void exit() { m_active = false; onExit(); }

	virtual void onEnter() {}
	virtual void onExit() {}
	virtual void onPushed() {}
	virtual void onPopped() {}

private:
	bool m_active = false;
};

