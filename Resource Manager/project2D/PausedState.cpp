#include "States.h"
#include "GameStateManager.h"

PausedState::PausedState()
{
}

void PausedState::onUpdate(float deltaTime)
{
	if (m_input->wasKeyReleased(aie::INPUT_KEY_SPACE))
	{
		m_gameStateManager->popState();
	}
}

void PausedState::createGameObjects()
{

}

void PausedState::onDraw()
{
	m_renderer->drawBox(
		m_gameStateManager->m_application->getWindowWidth() / 2.0f,
		m_gameStateManager->m_application->getWindowHeight() / 2.0f,
		m_gameStateManager->m_application->getWindowWidth() / 2.0f,
		m_gameStateManager->m_application->getWindowHeight() / 2.0f);
}

PausedState::~PausedState()
{
}