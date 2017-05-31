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
	virtual void HandleCollision(Hit hit);

	~Asteroid();

private:
	float m_speed;
	float m_rotationSpeed;
	Vector3 m_direction;
	int m_maxSpeed = 4;
	int m_minSpeed = 2;
	int m_maxRotationSpeed = 1;
};

