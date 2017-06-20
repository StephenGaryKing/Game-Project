#pragma once
#include "DynamicArray.h"
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

	DynamicArray< std::shared_ptr<ResourceBase> > m_resources; 

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
		for (int i = 0; i < m_resources.size(); i++)
		{
			if (filename.compare(m_resources[i]->getFilename()) == 0)
				return m_resources[i];
		}

		switch (type) 
		{ 
			case ResourceType::TEXTURE: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Texture>(filename)); 
				m_resources.pushBack(resource);
				return resource; 
			} 
			
			case ResourceType::FONT: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Font>(filename, 32)); 
				m_resources.pushBack(resource); 
				return resource; 
			} 
			
			case ResourceType::AUDIO: 
			{ 
				std::shared_ptr<ResourceBase> resource(new Resource<aie::Audio>(filename)); 
				m_resources.pushBack(resource); 
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
		for (int i = 0; i < m_resources.size(); i++)
		{
			if (m_resources[i].use_count() == 1)
				m_resources.erase(i);
			else
				i++;
		}

		//for (std::vector< std::shared_ptr<ResourceBase> >::iterator it =
		//	m_resources.begin(); it != m_resources.end(); )
		//{
		//	if ((*it).use_count() == 1)
		//		it = m_resources.erase(it);
		//	else
		//		++it;
		//}
	} 
};