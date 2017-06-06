#include "Application2D.h"
#include "Input.h"
#include <iostream>
#include <glm\glm.hpp>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	setBackgroundColour(0.7f, 0.7f, 0.7f, 1);


	m_gameObjectFactory = std::unique_ptr<GameObjectFactory>(new GameObjectFactory());

	//create some GameObjects to store in the factory
	std::shared_ptr<GameObject> m_player(new GameObject("player", "./textures/ship.png"));
	m_player->setPosition(200, 300);

	std::shared_ptr<GameObject> m_lRock(new GameObject("lRock", "./textures/rock_large.png"));
	m_lRock->setPosition(500, 400);

	m_gameObjectFactory->addPrototype(m_player);
	m_gameObjectFactory->addPrototype(m_lRock);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (m_timer >= 0.5f)
	{
		m_timer = 0;

		std::shared_ptr<IPrototype> gameObjectClone;
		if (rand() % 2 == 0)
			gameObjectClone = m_gameObjectFactory->create("player");
		else
			gameObjectClone = m_gameObjectFactory->create("lRock");

		// dynamically cast the shared pointer from IPrototype to snack
		std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
		gameObject->setVelocity(50.0f - rand() % 100, 50.0f - rand() % 100);
		m_gameObjects.push_back(gameObject);
	}

	for ( auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->Update(deltaTime, input);
		++it;
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw stuff
	for (std::shared_ptr<GameObject> gameObject : m_gameObjects)
	{
		gameObject->draw(m_2dRenderer);
	}

	// done drawing sprites
	m_2dRenderer->end();
}