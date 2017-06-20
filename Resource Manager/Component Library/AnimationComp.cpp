#include "AnimationComp.h"
#include "GameObject.h"
#include "Matrix3.h"
#include "TransformComp.h"

void AnimationComp::update(GameObject* gameObject, float deltaTime)
{
	m_timer += deltaTime;
	if (m_timer > 1.0f / m_fps)
	{
		m_timer = 0;
		m_frameToRender++;
		if (m_frameToRender > m_amountOfFrames -1)
		{
			if (m_looping)
				m_frameToRender = 0;
			else
				delete this;
		}
	}
}

void AnimationComp::draw(GameObject* gameObject)
{
	Matrix3 transform = gameObject->getComponent<TransformComp>(ComponentType::TRANSFORM)->getTransform();
	gameObject->m_renderer->drawSpriteTransformed3x3(m_frames[m_frameToRender]->as<aie::Texture>(), transform);
}