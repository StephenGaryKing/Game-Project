#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Texture.h"
class InGameState
	:public GameState
{
public:
	InGameState();
	virtual ~InGameState() {}

	virtual int onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);

private:

	GameObject*						m_player;
	GameObject**					m_asteroids;

	aie::Texture*					m_playerTexture;
	aie::Texture*					m_asteroidTexture;

	int								m_amountOfAsteroids = 10;
};

