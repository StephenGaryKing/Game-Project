#pragma once
#include "GameState.h"
#include "Button.h"
class MenuState
	:public GameState
{
public:
	MenuState();
	virtual ~MenuState() {}

	virtual int onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);

private:
	Button*		m_playBtn;
	Button*		m_exitBtn;
};

