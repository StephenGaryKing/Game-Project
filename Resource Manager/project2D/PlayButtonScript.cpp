#include "PlayButtonScript.h"
#include "GameObject.h"
#include "ButtonComp.h"

void PlayButtonScript::update(GameObject* gameObject, float deltaTime)
{
<<<<<<< HEAD
	if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
		m_gameStateManager->pushState((int)eGameState::INGAME);
=======
	if (m_gameStateManager->getState((int)eGameState::MENU))
		if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
			m_gameStateManager->pushState((int)eGameState::INGAME);
>>>>>>> origin/master
}

void PlayButtonScript::draw(GameObject* gameObject)
{

}