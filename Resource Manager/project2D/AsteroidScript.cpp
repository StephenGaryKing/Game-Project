#include "AsteroidScript.h"
#include "GameObject.h"
#include "TransformComp.h"
#include "TextureComp.h"

void AsteroidScript::update(GameObject* gameObject, float deltaTime)
{
	gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position = gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position + m_velocity;
	if (gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.x < 0)
		m_velocity.x = -m_velocity.x;
	if (gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.y < 0)
		m_velocity.y = -m_velocity.y;
	if (gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.x > 1280)
		m_velocity.x = -m_velocity.x;
	if (gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.y > 720)
		m_velocity.y = -m_velocity.y;
}

void AsteroidScript::draw(GameObject* gameObject)
{

}