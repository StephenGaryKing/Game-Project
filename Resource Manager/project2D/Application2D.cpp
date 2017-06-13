#include "Application2D.h"
#include "Input.h"
#include <iostream>
#include "PlayerScript.h"
#include "AsteroidScript.h"
#include <glm\glm.hpp>
#include <chrono>
#include "States.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	srand((unsigned int)time(NULL));

	m_2dRenderer = new aie::Renderer2D();
	m_input = aie::Input::getInstance();

	gameStateManager = new GameStateManager((int)eGameState::STATE_COUNT, m_input, m_2dRenderer);

	setBackgroundColour(0.7f, 0.7f, 0.7f, 1);


	m_gameObjectFactory = std::unique_ptr<GameObjectFactory>(new GameObjectFactory());

	// register states

	gameStateManager->registerState((int)eGameState::SPLASH, new SpashScreenState());
	gameStateManager->registerState((int)eGameState::MENU, new MainMenuState());
	gameStateManager->registerState((int)eGameState::INGAME, new InGameState());
	gameStateManager->registerState((int)eGameState::PAUSE, new PausedState());

	gameStateManager->pushState((int)eGameState::INGAME);

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

	gameStateManager->update(deltaTime);

	//for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	//{
	//	(*it)->update(deltaTime, input);
	//	++it;
	//}

	/*

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

	*/

}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	gameStateManager->draw();

	// done drawing sprites
	m_2dRenderer->end();
}