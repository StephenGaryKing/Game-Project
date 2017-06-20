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
	m_gameObjectFactory = std::shared_ptr<GameObjectFactory>(new GameObjectFactory());

	m_gameStateManager = std::shared_ptr<GameStateManager>(new GameStateManager((int)eGameState::STATE_COUNT, m_input, m_2dRenderer, m_gameObjectFactory));
	m_gameStateManager->m_application = this;

	setBackgroundColour(0.7f, 0.7f, 0.7f, 1);

	// register states

	m_gameStateManager->registerState((int)eGameState::SPLASH, new SplashScreenState());
	m_gameStateManager->registerState((int)eGameState::MENU, new MainMenuState());
	m_gameStateManager->registerState((int)eGameState::INGAME, new InGameState());
	m_gameStateManager->registerState((int)eGameState::PAUSE, new PausedState());

	m_gameStateManager->pushState((int)eGameState::SPLASH);

	m_cameraX = 0;
	m_cameraY = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {
	m_gameStateManager->update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_gameStateManager->draw();

	// done drawing sprites
	m_2dRenderer->end();
}