#include "PlayerScript.h"
#include "GameObject.h"
#include "MouseInputComp.h"
#include "TransformComp.h"

void PlayerScript::update(GameObject* gameObject, float deltaTime)
{
	gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.x = gameObject->getComponent<MouseInputComp>(ComponentType::MOUSEINPUT)->m_mouseX;
	gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.y = gameObject->getComponent<MouseInputComp>(ComponentType::MOUSEINPUT)->m_mouseY;
}

void PlayerScript::draw(GameObject* gameObject)
{
	
}