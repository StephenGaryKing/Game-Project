#include "States.h"
#include "ComponentList.h"
#include "PlayerScript.h"
#include "AsteroidScript.h"

InGameState::InGameState()
{
}

void InGameState::onEnter()
{
	// add the player

	//declare the components that will be used
	ComponentPtr transform(new TransformComp(Vector3(500, 500, 1), Vector3(0, 0, 0)));
	ComponentPtr playerTexture(new TextureComp("./textures/ship.png"));
	ComponentPtr input(new MouseInputComp());
	ComponentPtr playerScript(new PlayerScript());

	//create some GameObjects to store in the factory
	std::shared_ptr<GameObject> m_player(new GameObject("player"));

	m_player->addComponent(transform);
	m_player->addComponent(playerTexture);
	m_player->addComponent(input);
	m_player->addComponent(playerScript);
	m_player->m_input = m_input;
	m_player->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_player);

	// add the asteroids

	//declare the components that will be used
	ComponentPtr asteroidTransform(new TransformComp(Vector3(600, 400, 1), Vector3(0, 0, 0)));
	ComponentPtr asteroidSTexture(new TextureComp("./textures/rock_small.png"));
	ComponentPtr asteroidScript(new AsteroidScript());

	//create some GameObjects to store in the factory
	std::shared_ptr<GameObject> m_SRock(new GameObject("SRock"));

	m_SRock->addComponent(asteroidTransform);
	m_SRock->addComponent(asteroidSTexture);
	m_SRock->addComponent(asteroidScript);
	m_SRock->m_input = m_input;
	m_SRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_SRock);


	//create some GameObjects to store in the factory
	ComponentPtr asteroidMTexture(new TextureComp("./textures/rock_medium.png"));
	std::shared_ptr<GameObject> m_MRock(new GameObject("MRock"));

	m_MRock->addComponent(asteroidTransform);
	m_MRock->addComponent(asteroidMTexture);
	m_MRock->addComponent(asteroidScript);
	m_MRock->m_input = m_input;
	m_MRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_MRock);

	//create some GameObjects to store in the factory
	ComponentPtr asteroidLTexture(new TextureComp("./textures/rock_large.png"));
	std::shared_ptr<GameObject> m_LRock(new GameObject("LRock"));

	m_LRock->addComponent(asteroidTransform);
	m_LRock->addComponent(asteroidLTexture);
	m_LRock->addComponent(asteroidScript);
	m_LRock->m_input = m_input;
	m_LRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_LRock);

	// how to create a game object from the factory
	std::shared_ptr<IPrototype> gameObjectClone;
	gameObjectClone = m_gameObjectFactory->create("player");
	std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);

	gameObjectClone = m_gameObjectFactory->create("LRock");
	gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);

}

void InGameState::onExit()
{

}

void InGameState::onUpdate(float deltaTime)
{

}

void InGameState::onDraw()
{
	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->draw();
		++it;
	}
}

InGameState::~InGameState()
{
}