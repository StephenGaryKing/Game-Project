#include "Asteroid.h"



Asteroid::Asteroid(Matrix3 transform, aie::Texture* texture, std::vector<Vector3> points)
{
	m_transform = transform;
	m_transform[2].x = (float)(rand() % 1280);
	m_transform[2].y = (float)(rand() % 720);
	m_texture = texture;
	m_points = points;
	m_size = Vector3((float)texture->getWidth(), (float)texture->getHeight(), 0.0f);
	m_direction = Vector3((float)(rand()% 90) + 10, (float)(rand() % 90) + 10, 0.0f);
	if (rand() % 100 < 50)
		m_direction.x *= -1;
	if (rand() % 100 < 50)
		m_direction.y *= -1;
	m_direction.normalise();
	m_speed = (float)(rand() % (m_maxSpeed - m_minSpeed) + m_minSpeed);
}

void Asteroid::Update(float deltaTime, aie::Input* input)
{
	m_transform[2] = m_transform[2] + (m_direction * m_speed);
	if (m_transform[2].x < 0)
		m_direction.x *= -1;
	if (m_transform[2].y < 0)
		m_direction.y *= -1;
	if (m_transform[2].x > 1280)
		m_direction.x *= -1;
	if (m_transform[2].y > 720)
		m_direction.y *= -1;
}

void Asteroid::Draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->drawSpriteTransformed3x3(m_texture, m_transform);
}

void Asteroid::HandleCollision(GameObject* other, Hit hit)
{

}

void Asteroid::HandleCollision(Hit hit)
{

}

Asteroid::~Asteroid()
{
}
