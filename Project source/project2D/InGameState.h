#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Texture.h"
#include <vector>
class InGameState
	:public GameState
{
public:
	InGameState();
	virtual ~InGameState() {}

	virtual int onUpdate(aie::Input* input, float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);

private:

	void ActivateNextGameObjects(GameObject** list, GameObject* activator, int listSize, int amount);

	GameObject*						m_player;
	std::vector<GameObject*>		m_largeAsteroids;
	std::vector<GameObject*>		m_mediumAsteroids;
	std::vector<GameObject*>		m_smallAsteroids;

	aie::Texture*					m_playerTexture;
	aie::Texture*					m_largeAsteroidTexture;
	aie::Texture*					m_mediumAsteroidTexture;
	aie::Texture*					m_smallAsteroidTexture;

	char*							m_largeAsteroidTextureName = "./textures/rock_large.png";
	char*							m_mediumAsteroidTextureName = "./textures/rock_medium.png";
	char*							m_smallAsteroidTextureName = "./textures/rock_small.png";
	
	int								m_amountOfAsteroids = 10;
};

