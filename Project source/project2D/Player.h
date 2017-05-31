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
	aie::Texture* explosionAnimation[8];
	aie::Texture* spawnAnimation[16];
};

