#pragma once
#include "GameState.h"
class MenuState
	:public GameState
{
public:
	MenuState() {}
	virtual ~MenuState() {}

	virtual void onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);
};

