#include "QuitButtonScript.h"
#include "GameObject.h"
#include "ButtonComp.h"

void QuitButtonScript::update(GameObject* gameObject, float deltaTime)
{
	if (m_gameStateManager->getState((int)eGameState::MENU))
		if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
			m_gameStateManager->m_application->quit();
}

void QuitButtonScript::draw(GameObject* gameObject)
{

}