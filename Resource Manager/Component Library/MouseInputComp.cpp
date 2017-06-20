#include "MouseInputComp.h"
#include "GameObject.h"

void MouseInputComp::update(GameObject* gameObject, float deltaTime)
{
	m_mouseX = (float)gameObject->m_input->getMouseX();
	m_mouseY = (float)gameObject->m_input->getMouseY();
	for (int i = 0; i < 3; i++)
	{
		if (m_mouseClicked[i])
			m_mouseClicked[i] = false;

		if (gameObject->m_input->isMouseButtonDown(i))
			m_mouseDown[i] = true;

		if (gameObject->m_input->isMouseButtonUp(i) && m_mouseDown[i])
		{
			m_mouseClicked[i] = true;
			m_mouseDown[i] = false;
		}
	}
}

void MouseInputComp::draw(GameObject* gameObject)
{

}