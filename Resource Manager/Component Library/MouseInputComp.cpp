#include "MouseInputComp.h"
#include "GameObject.h"

void MouseInputComp::update(GameObject* gameObject, float deltaTime)
{
	m_mouseX = (float)gameObject->m_input->getMouseX();
	m_mouseY = (float)gameObject->m_input->getMouseY();
}

void MouseInputComp::draw(GameObject* gameObject)
{

}