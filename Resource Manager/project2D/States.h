#pragma once
#include "GameState.h"

class SplashScreenState
	: public GameState
{
public:
	SplashScreenState();
	~SplashScreenState();

	virtual void onPushed();
	virtual void onPopped();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

	float m_timer = 0;
	float m_timeToWait = 5;

	void createGameObjects();
};


class MainMenuState
	: public GameState
{
public:
	MainMenuState();
	~MainMenuState();

	virtual void onPushed();
	virtual void onPopped();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

	void createGameObjects();
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

	void createGameObjects();
	
};


class PausedState
	: public GameState
{
public:
	PausedState();
	~PausedState();

	virtual void onEnter();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

	void createGameObjects();
};

class GameOverState
	: public GameState
{
public:
	GameOverState();
	~GameOverState();

	virtual void onEnter();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

	void createGameObjects();
};