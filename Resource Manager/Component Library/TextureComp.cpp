#include "TextureComp.h"
#include "GameObject.h"
#include "TransformComp.h"

void TextureComp::update(GameObject* gameObject, float deltaTime)
{
	
}

void TextureComp::draw(GameObject* gameObject)
{
	Matrix3 transform = gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->getTransform();
	gameObject->m_renderer->drawSpriteTransformed3x3(m_texture->as<aie::Texture>(), transform);
}