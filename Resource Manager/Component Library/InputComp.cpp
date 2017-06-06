#include "InputComp.h"
#include "GameObject.h"

void InputComp::update(GameObject* gameObject, float deltaTime)
{
	m_mouseX = gameObject->m_input->getMouseX();
	m_mouseY = gameObject->m_input->getMouseY();
}

void InputComp::draw(GameObject* gameObject)
{

}