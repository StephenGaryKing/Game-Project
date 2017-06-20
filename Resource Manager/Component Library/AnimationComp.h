#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include <string>

class AnimationComp
	: public Component
{
public:
	AnimationComp(std::string foldername, int amountOfFrames, int fps)
	{
		m_folderName = foldername;
		m_amountOfFrames = amountOfFrames;
		m_fps = fps;
		m_componentType = ComponentType::ANIMATION;

		m_frames = new std::shared_ptr<ResourceBase>[amountOfFrames];
		for (int i = 0; i < amountOfFrames; i++)
		{
			std::string temp = foldername + "frame_" + std::to_string(i+1) + ".png";
			m_frames[i] = ResourceManager::getInstance().get(temp.c_str(), ResourceManager::TEXTURE);
		}
	}

	virtual ComponentPtr clone()
	{
		return ComponentPtr(new AnimationComp(*this));
	}

	virtual void update(GameObject* gameObject, float deltaTime);

	virtual void draw(GameObject* gameObject);

	std::string		m_folderName;
	int				m_amountOfFrames;
	std::shared_ptr<ResourceBase>* m_frames;
	int				m_fps;
	float			m_timer = 0;
	int				m_frameToRender = 0;
	bool			m_looping = false;
};