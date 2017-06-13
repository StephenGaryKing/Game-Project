#pragma once
#include "GameState.h"
#include <memory>
#include <list>
#include "GameObject.h"
#include "GameObjectFactory.h"

class SpashScreenState
	: public GameState
{
public:
	SpashScreenState();
	~SpashScreenState();

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
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

	std::unique_ptr<GameObjectFactory> m_gameObjectFactory;
	std::list<std::shared_ptr<GameObject>>	m_gameObjects;
	
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