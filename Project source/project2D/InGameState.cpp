#include "InGameState.h"

InGameState::InGameState()
{
	m_playerTexture = new aie::Texture("./textures/ship.png");
	m_asteroidTexture = new aie::Texture("./textures/rock_small.png");

	m_player = new GameObject(Matrix3(), m_playerTexture, {});
	m_asteroids = new GameObject*[m_amountOfAsteroids];
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_asteroids[i] = new GameObject(Matrix3(), m_asteroidTexture, {});
		m_asteroids[i]->transform[2] = { 300,300,1 };
	}
}

void InGameState::onUpdate(aie::Input* input, float deltaTime)
{
	m_player->transform[2].x = (float)input->getMouseX();
	m_player->transform[2].y = (float)input->getMouseY();
	m_player->UpdateCollisions(m_asteroids, m_amountOfAsteroids);
}

void InGameState::onDraw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->drawSpriteTransformed3x3(m_player->texture, m_player->transform);
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		renderer->drawSpriteTransformed3x3(m_asteroids[i]->texture, m_asteroids[i]->transform);
	}
}
