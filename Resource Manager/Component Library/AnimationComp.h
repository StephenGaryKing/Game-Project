#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include <string>

class AnimationComp
	: public Component
{
public:
	AnimationComp(std::string foldername, int amountOfFrames)
	{
		m_folderName = foldername;
		m_amountOfFrames = amountOfFrames;
		m_componentType = ComponentType::ANIMATION;

		m_frames = new aie::Texture*[amountOfFrames];
		for (int i = 1; i < amountOfFrames; i++)
		{
			std::string temp = foldername + "frame_" + std::to_string(i) + ".png";
			m_frames[i - 1] = new aie::Texture(temp.c_str());
		}
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	std::string		m_folderName;
	int				m_amountOfFrames;
	aie::Texture**	m_frames;
	bool			m_looping;
};