#pragma once
#include "GameObject.h"
class Asteroid
	:public GameObject
{
public:
	Asteroid() {}
	Asteroid(Matrix3 transform, aie::Texture* texture, std::vector<Vector3> points);

	virtual void Update(float deltaTime, aie::Input* input);
	virtual void Draw(aie::Renderer2D* renderer);
	virtual void HandleCollision(GameObject* other, Hit hit);
	virtual void HandleCollision(Hit hit);

	~Asteroid();

private:
	float m_speed;
	Vector3 m_direction;
	int m_maxSpeed = 10;
	int m_minSpeed = 2;
};

