#include "MenuButtonScript.h"
#include "GameObject.h"
#include "ButtonComp.h"

void MenuButtonScript::update(GameObject* gameObject, float deltaTime)
{
	if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
		m_gameStateManager->popDownTo((int)eGameState::MENU);
}

void MenuButtonScript::draw(GameObject* gameObject)
{

}