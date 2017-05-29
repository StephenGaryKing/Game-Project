#pragma once
#include "GameState.h"
class PauseState
	:public GameState
{
public:
	PauseState() {}
	virtual ~PauseState() {}

	virtual void onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);
};

