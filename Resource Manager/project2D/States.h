#pragma once
#include "GameState.h"

class SplashScreenState
	: public GameState
{
public:
	SplashScreenState();
	~SplashScreenState();

	virtual void onEnter();
	virtual void onPopped();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

	float m_timer = 0;
};


class MainMenuState
	: public GameState
{
public:
	MainMenuState();
	~MainMenuState();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
};


class InGameState
	: public GameState
{
public:
	InGameState();
	~InGameState();

	virtual void onEnter();
	virtual void onExit();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	
};


class PausedState
	: public GameState
{
public:
	PausedState();
	~PausedState();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
};