#pragma once
#include "GameObject.h"

class Player
	:public GameObject
{
public:
	Player() {}
	Player(Matrix3 transform, aie::Texture* texture, std::vector<Vector3> points);

	virtual void Update(float deltaTime, aie::Input* input);
	virtual void Draw(aie::Renderer2D* renderer);
	virtual void HandleCollision(GameObject* other, Hit hit);
	virtual void HandleCollision(Hit hit);

	void Respawn();

	~Player();

private:
	TexturePtr m_explosionAnimation[8];
	TexturePtr m_spawnAnimation[16];
	bool m_dead = false;

	float m_timePassed = 0;
	float m_deathTime = 4.0f;
	float m_respawnTime = 3.5f;
};

