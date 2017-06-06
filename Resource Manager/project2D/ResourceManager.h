#pragma once
#include <vector>
#include "Resource.h"
#include "Texture.h"
#include "Font.h"
#include "Audio.h"

class ResourceManager 
{
public:
	// define an enum to allow us to specify what type of resource we want 
	// to get from the Resource Manager
	enum ResourceType {
		TEXTURE = 0,
		FONT,
		AUDIO
	};

	std::vector< std::shared_ptr<ResourceBase> > m_resources; 

	ResourceManager() {};
	ResourceManager(const ResourceManager&) {}; 
	ResourceManager& operator=(const ResourceManager&) {}; 

public:
	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}
	~ResourceManager() {}; 

	std::shared_ptr<ResourceBase> get(const std::string filename, ResourceType type) 
	{
		std::vector< std::shared_ptr<ResourceBase> >::iterator it;
		for (it = m_resources.begin(); it != m_resources.end(); it++)
		{
			if (filename.compare((*it)->getFilename()) == 0)
			{
				return (*it);
			}
		}

		switch (type) 
		{ 
			case ResourceType::TEXTURE: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Texture>(filename)); 
				m_resources.push_back(resource);
				return resource; 
			} 
			
			case ResourceType::FONT: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Font>(filename, 32)); 
				m_resources.push_back(resource); 
				return resource; 
			} 
			
			case ResourceType::AUDIO: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Audio>(filename)); 
				m_resources.push_back(resource); 
				return resource; 
			} 
			
			default: 
				return nullptr; 
		}
	}
	int getCount() 
	{
		return m_resources.size();
	}
	void collectGarbage() 
	{
		for (std::vector< std::shared_ptr<ResourceBase> >::iterator it =
			m_resources.begin(); it != m_resources.end(); )

		{
			if ((*it).use_count() == 1)
				it = m_resources.erase(it);
			else
				++it;
		}
	} 
};