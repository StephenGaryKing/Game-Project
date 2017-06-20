#include "QuitButtonScript.h"
#include "GameObject.h"
#include "ButtonComp.h"

void QuitButtonScript::update(GameObject* gameObject, float deltaTime)
{
<<<<<<< HEAD
	if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
		m_gameStateManager->m_application->quit();
=======
	if (m_gameStateManager->getState((int)eGameState::MENU))
		if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
			m_gameStateManager->m_application->quit();
>>>>>>> origin/master
}

void QuitButtonScript::draw(GameObject* gameObject)
{

}