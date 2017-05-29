#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "MenuState.h"
#include "InGameState.h"
#include "PauseState.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {
	for (int i = 0; i < 10; i++)
	{
		m_texture[i];
	}
}

bool Application2D::startup() {

	m_input = aie::Input::getInstance();

	m_gameStateManager = new GameStateManager((int)eGameState::STATE_COUNT);

	m_gameStateManager->registerState( (unsigned int)eGameState::MENU, new MenuState() );
	m_gameStateManager->registerState((unsigned int)eGameState::INGAME, new InGameState());
	m_gameStateManager->registerState((unsigned int)eGameState::PAUSE, new PauseState());

	m_gameStateManager->pushState((unsigned int)eGameState::MENU);
	m_gameStateManager->update(m_input,  0);

	setBackgroundColour(0.7f, 0.7f, 0.7f, 1);
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	//initialize player data

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	if (m_gameStateManager->activeStateCount() > 0)
	{
		m_timer += deltaTime;
		m_gameStateManager->update(m_input, deltaTime);
	}
	

	// exit the application
	if (m_input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing
	m_2dRenderer->begin();
	
	if (m_gameStateManager->activeStateCount() > 0)
	{
		m_gameStateManager->draw(m_2dRenderer);
	}
	//draw FPS
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing
	m_2dRenderer->end();
}