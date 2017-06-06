#include "GameObjectFactory.h"
#include "IPrototype.h"


GameObjectFactory::GameObjectFactory(){}


GameObjectFactory::~GameObjectFactory(){}

void GameObjectFactory::addPrototype(std::shared_ptr<IPrototype> prototype)
{
	m_prototypes.push_back(prototype);
}

std::shared_ptr<IPrototype> GameObjectFactory::create(const char* name)
{
	for (std::shared_ptr<IPrototype> proto : m_prototypes)
	{
		if (proto->getName().compare(name) == 0)
		{
			return proto->clone();
		}
	}
	return nullptr;
}