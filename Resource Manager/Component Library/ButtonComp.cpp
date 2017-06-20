#include "ButtonComp.h"
#include "MouseInputComp.h"
#include "TransformComp.h"
#include "TextureComp.h"
#include "GameObject.h"

void ButtonComp::update(GameObject* gameObject, float deltaTime)
{
	if (gameObject->getComponent<MouseInputComp>(MOUSEINPUT)->m_mouseClicked[0] == true)
	{
		float* mouseX = &(gameObject)->getComponent<MouseInputComp>(MOUSEINPUT)->m_mouseX;
		float* mouseY = &(gameObject)->getComponent<MouseInputComp>(MOUSEINPUT)->m_mouseY;
		Vector3* position = &(gameObject)->getComponent<TransformComp>(TRANSFORM)->m_position;
		float* scale = &(gameObject)->getComponent<TransformComp>(TRANSFORM)->m_scale;
		std::shared_ptr<ResourceBase>* texture = &(gameObject)->getComponent<TextureComp>(TEXTURE)->m_texture;

		if ((*mouseX) > ((*position).x - ((*texture)->as<aie::Texture>()->getWidth() / 2) * (*scale)) && (*mouseX) < ((*position).x + ((*texture)->as<aie::Texture>()->getWidth() / 2) * (*scale)))
			if ((*mouseY) > ((*position).y - ((*texture)->as<aie::Texture>()->getHeight() / 2) * (*scale)) && (*mouseY) < ((*position).y + ((*texture)->as<aie::Texture>()->getHeight() / 2) * (*scale)))
			{
				m_clicked = true;
				return;
			}
	}
	m_clicked = false;
}

void ButtonComp::draw(GameObject* gameObject)
{

}