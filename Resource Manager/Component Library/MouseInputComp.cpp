#include "MouseInputComp.h"
#include "GameObject.h"

void MouseInputComp::update(GameObject* gameObject, float deltaTime)
{
	m_mouseX = (float)gameObject->m_input->getMouseX();
	m_mouseY = (float)gameObject->m_input->getMouseY();
	for (int i = 0; i < 3; i++)
	{
		if (gameObject->m_input->isMouseButtonDown(i))
			m_keyPressed[i] = true;
		else
			m_keyPressed[i] = false;
	}
}

void MouseInputComp::draw(GameObject* gameObject)
{

}