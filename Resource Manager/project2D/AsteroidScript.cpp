#include "AsteroidScript.h"
#include "GameObject.h"
#include "TransformComp.h"
#include "TextureComp.h"

void AsteroidScript::update(GameObject* gameObject, float deltaTime)
{
	gameObject->getComponent<TransformComp>(TRANSFORM)->m_position = gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position + m_velocity;
	if (gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.x < 0)
	{
		m_velocity.x = -m_velocity.x;
		gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.x = 0;
	}
	if (gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.y < 0)
	{
		m_velocity.y = -m_velocity.y;
		gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.y = 0;
	}
	if (gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.x > (float)(m_gameStateManager->m_application->getWindowWidth()))
	{
		m_velocity.x = -m_velocity.x;
		gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.x = (float)(m_gameStateManager->m_application->getWindowWidth());
	}
	if (gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.y > (float)(m_gameStateManager->m_application->getWindowHeight()))
	{
		m_velocity.y = -m_velocity.y;
		gameObject->getComponent<TransformComp>(TRANSFORM)->m_position.y = (float)(m_gameStateManager->m_application->getWindowHeight());
	}
}

void AsteroidScript::draw(GameObject* gameObject)
{

}

void AsteroidScript::setPosition(std::shared_ptr<GameObject> gameObject, Vector3 position)
{
	gameObject->getComponent<TransformComp>(TRANSFORM)->m_position = position;
}