#pragma once
#include "GameState.h"
class PauseState
	:public GameState
{
public:
	PauseState() {}
	virtual ~PauseState() {}

	virtual int onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);
};

