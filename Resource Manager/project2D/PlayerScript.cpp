#include "PlayerScript.h"
#include "GameObject.h"
#include "MouseInputComp.h"
#include "TransformComp.h"
#include "TextureComp.h"

void PlayerScript::update(GameObject* gameObject, float deltaTime)
{
	gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.x = gameObject->getComponent<MouseInputComp>(ComponentType::INPUT)->m_mouseX;
	gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->m_position.y = gameObject->getComponent<MouseInputComp>(ComponentType::INPUT)->m_mouseY;
}

void PlayerScript::draw(GameObject* gameObject)
{
	
}