#include "PlayButtonScript.h"
#include "GameObject.h"
#include "ButtonComp.h"

void PlayButtonScript::update(GameObject* gameObject, float deltaTime)
{
	if (gameObject->getComponent<ButtonComp>(BUTTON)->m_clicked)
		m_gameStateManager->pushState((int)eGameState::INGAME);
}

void PlayButtonScript::draw(GameObject* gameObject)
{

}