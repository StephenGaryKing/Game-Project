#include "InGameState.h"
#include "Player.h"
#include "Asteroid.h"

InGameState::InGameState()
{
	m_playerTexture = new aie::Texture("./textures/ship.png");
	m_largeAsteroidTexture = new aie::Texture(m_largeAsteroidTextureName);
	m_mediumAsteroidTexture	= new aie::Texture(m_mediumAsteroidTextureName);
	m_smallAsteroidTexture = new aie::Texture(m_smallAsteroidTextureName);

	m_player = new Player(Matrix3(), m_playerTexture, {Vector3()});

	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_largeAsteroids.push_back(new Asteroid(Matrix3(), m_largeAsteroidTexture, {Vector3()}));
	}
	for (int i = 0; i < m_amountOfAsteroids * 2; i++)
	{
		m_mediumAsteroids.push_back(new Asteroid(Matrix3(), m_mediumAsteroidTexture, { Vector3() }));
		m_mediumAsteroids.back()->m_enabled = false;
	}
	for (int i = 0; i < m_amountOfAsteroids * 4; i++)
	{
		m_smallAsteroids.push_back(new Asteroid(Matrix3(), m_smallAsteroidTexture, { Vector3() }));
		m_smallAsteroids.back()->m_enabled = false;
	}
}

int InGameState::onUpdate(aie::Input* input, float deltaTime)
{
	m_player->Update(deltaTime, input);

	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		if (m_largeAsteroids[i]->m_enabled)
		{
			m_largeAsteroids[i]->Update(deltaTime, input);
			if (m_largeAsteroids[i]->IsColliding(m_player))
			{
				m_largeAsteroids[i]->HandleCollision(m_player);
				ActivateNextGameObjects(&m_mediumAsteroids[0], m_largeAsteroids[i], m_amountOfAsteroids, 2);
				m_largeAsteroids[i]->m_enabled = false;
				m_player->m_enabled = false;
			}
		}
	}
	for (int i = 0; i < m_amountOfAsteroids * 2; i++)
	{
		if (m_mediumAsteroids[i]->m_enabled)
		{
			m_mediumAsteroids[i]->Update(deltaTime, input);
			if (m_mediumAsteroids[i]->IsColliding(m_player))
			{
				m_mediumAsteroids[i]->HandleCollision(m_player);
				ActivateNextGameObjects(&m_smallAsteroids[0], m_mediumAsteroids[i], m_amountOfAsteroids, 2);
				m_mediumAsteroids[i]->m_enabled = false;
			}
		}
	}
	for (int i = 0; i < m_amountOfAsteroids * 4; i++)
	{
		if (m_smallAsteroids[i]->m_enabled)
		{
			m_smallAsteroids[i]->Update(deltaTime, input);
			if (m_smallAsteroids[i]->IsColliding(m_player))
			{
				m_smallAsteroids[i]->HandleCollision(m_player);
				m_smallAsteroids[i]->m_enabled = false;
			}
		}
	}
	
	return -1;
}

void InGameState::onDraw(aie::Renderer2D* renderer)
{
	m_player->Draw(renderer);
	for (int i = 0; i < m_amountOfAsteroids; i++)
	{
		m_largeAsteroids[i]->Draw(renderer);
	}
	for (int i = 0; i < m_amountOfAsteroids * 2; i++)
	{
		m_mediumAsteroids[i]->Draw(renderer);
	}
	for (int i = 0; i < m_amountOfAsteroids * 4; i++)
	{
		m_smallAsteroids[i]->Draw(renderer);
	}
}

void InGameState::ActivateNextGameObjects(GameObject** list, GameObject* activator, int listSize, int amount)
{
	for (int i = 0; i < listSize; i++)
	{
		if (!list[i]->m_enabled && amount > 0)
		{
			list[i]->m_enabled = true;
			list[i]->m_transform[2].x = activator->m_transform[2].x;
			list[i]->m_transform[2].y = activator->m_transform[2].y;
			amount--;
		}

	}
}
