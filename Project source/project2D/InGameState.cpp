#include "InGameState.h"
#include "Player.h"
#include "Asteroid.h"

InGameState::InGameState()
{
	m_playerTexture = new aie::Texture("./textures/ship.png");
	m_asteroidTexture = new aie::Texture("./textures/rock_small.png");

	m_player = new Player(Matrix3(), m_playerTexture, {Vector3()});
	m_asteroids = new GameObject*[m_amountOfAsteroids];
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_asteroids[i] = new Asteroid(Matrix3(), m_asteroidTexture, {Vector3()});
	}
}

int InGameState::onUpdate(aie::Input* input, float deltaTime)
{
	m_player->Update(deltaTime, input);
	m_player->UpdateCollisions(m_asteroids, m_amountOfAsteroids);
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_asteroids[i]->Update(deltaTime, input);
	}
	return -1;
}

void InGameState::onDraw(aie::Renderer2D* renderer)
{
	m_player->Draw(renderer);
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_asteroids[i]->Draw(renderer);
	}
}
