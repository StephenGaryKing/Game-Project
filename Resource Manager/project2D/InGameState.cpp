#include "States.h"
#include "ComponentList.h"
#include "PlayerScript.h"
#include "AsteroidScript.h"
#include "GameStateManager.h"

InGameState::InGameState()
{
}

void InGameState::onEnter()
{
	if (m_gameObjects.size() == 0)
		createGameObjects();
}

void InGameState::createGameObjects()
{
	// add the player

	//declare the components that will be used
	ComponentPtr playerTransform(new TransformComp(Vector3(0, 0, 1), Vector3(0, 0, 0)));
	ComponentPtr playerTexture(new TextureComp("./textures/ship.png"));
	ComponentPtr playerInput(new MouseInputComp());
	ComponentPtr playerScript(new PlayerScript());

	//create some GameObjects to store in the factory
	std::shared_ptr<GameObject> m_player(new GameObject("player"));

	m_player->addComponent(playerTransform);
	m_player->addComponent(playerTexture);
	m_player->addComponent(playerInput);
	m_player->addComponent(playerScript);
	m_player->getComponent<PlayerScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_player->m_input = m_input;
	m_player->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_player);

	// add the asteroids

	//declare the components that will be used
<<<<<<< HEAD
	ComponentPtr asteroidTransform(new TransformComp(Vector3(0, 0, 1), Vector3(0, 0, 0)));
=======
	ComponentPtr asteroidSTransform(new TransformComp(Vector3(0, 0, 1), Vector3(0, 0, 0)));
>>>>>>> origin/master
	ComponentPtr asteroidSTexture(new TextureComp("./textures/rock_small.png"));
	ComponentPtr asteroidScript(new AsteroidScript());

	//create some GameObjects to store in the factory
	std::shared_ptr<GameObject> m_SRock(new GameObject("SRock"));

	m_SRock->addComponent(asteroidSTransform);
	m_SRock->addComponent(asteroidSTexture);
	m_SRock->addComponent(asteroidScript);
	m_SRock->getComponent<AsteroidScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_SRock->m_input = m_input;
	m_SRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_SRock);


	//create some GameObjects to store in the factory
	ComponentPtr asteroidMTransform(new TransformComp(Vector3(0, 0, 1), Vector3(0, 0, 0)));
	ComponentPtr asteroidMTexture(new TextureComp("./textures/rock_medium.png"));
	std::shared_ptr<GameObject> m_MRock(new GameObject("MRock"));

	m_MRock->addComponent(asteroidMTransform);
	m_MRock->addComponent(asteroidMTexture);
	m_MRock->addComponent(asteroidScript);
	m_MRock->getComponent<AsteroidScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_MRock->m_input = m_input;
	m_MRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_MRock);

	//create some GameObjects to store in the factory
	ComponentPtr asteroidLTransform(new TransformComp(Vector3(0, 0, 1), Vector3(0, 0, 0)));
	ComponentPtr asteroidLTexture(new TextureComp("./textures/rock_large.png"));
	std::shared_ptr<GameObject> m_LRock(new GameObject("LRock"));

	m_LRock->addComponent(asteroidLTransform);
	m_LRock->addComponent(asteroidLTexture);
	m_LRock->addComponent(asteroidScript);
	m_LRock->getComponent<AsteroidScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_LRock->m_input = m_input;
	m_LRock->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_LRock);

	// how to create a game object from the factory
	std::shared_ptr<IPrototype> gameObjectClone;
	gameObjectClone = m_gameObjectFactory->create("player");
	std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);

	for (int i = 0; i < 5; i++)
	{
		gameObjectClone = m_gameObjectFactory->create("LRock");
		gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
		gameObject->getComponent<AsteroidScript>(SCRIPT)->setPosition(m_LRock, Vector3((float)(rand() % m_gameStateManager->m_application->getWindowWidth()), (float)(rand() % m_gameStateManager->m_application->getWindowHeight()), 1.0f));
		m_gameObjects.push_back(gameObject);

	}
}

void InGameState::onExit()
{

}

void InGameState::onUpdate(float deltaTime)
{
	if (m_active)
	{
<<<<<<< HEAD
		if (m_input->wasKeyPressed(aie::INPUT_KEY_SPACE))
=======
		if (m_input->wasKeyReleased(aie::INPUT_KEY_SPACE))
>>>>>>> origin/master
		{
			m_gameStateManager->pushState((int)eGameState::PAUSE);
		}

		for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
		{
			(*it)->update(deltaTime);
			++it;
		}
	}
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