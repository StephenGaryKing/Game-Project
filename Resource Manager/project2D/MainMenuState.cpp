#include "States.h"
#include "TransformComp.h"
#include "TextureComp.h"
#include "MouseInputComp.h"
#include "ButtonComp.h"
#include "PlayButtonScript.h"
#include "QuitButtonScript.h"
#include "GameStateManager.h"

MainMenuState::MainMenuState()
{
}

void MainMenuState::onPushed()
{
	if (m_gameObjects.size() == 0)
		createGameObjects();
}

void MainMenuState::createGameObjects()
{
	ComponentPtr playBtnTransform(new TransformComp(Vector3((float)m_gameStateManager->m_application->getWindowWidth() / 2, (float)m_gameStateManager->m_application->getWindowHeight() / 10 * 7, 1), Vector3(0, 0, 0), 4));
	ComponentPtr playBtnTexture(new TextureComp("./textures/startBtn.png"));
	ComponentPtr playBtnMouseInput(new MouseInputComp());
	ComponentPtr playBtnButtonInput(new ButtonComp());
	ComponentPtr playBtnScript(new PlayButtonScript());

	std::shared_ptr<GameObject> m_playBtn(new GameObject("playBtn"));

	m_playBtn->addComponent(playBtnTransform);
	m_playBtn->addComponent(playBtnTexture);
	m_playBtn->addComponent(playBtnMouseInput);
	m_playBtn->addComponent(playBtnButtonInput);
	m_playBtn->addComponent(playBtnScript);
	m_playBtn->getComponent<PlayButtonScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_playBtn->m_renderer = m_renderer;
	m_playBtn->m_input = m_input;

	m_gameObjectFactory->addPrototype(m_playBtn);

	ComponentPtr quitBtnTransform(new TransformComp(Vector3((float)m_gameStateManager->m_application->getWindowWidth() / 2, (float)m_gameStateManager->m_application->getWindowHeight() / 10 * 4, 1), Vector3(0, 0, 0), 2));
	ComponentPtr quitBtnTexture(new TextureComp("./textures/quitBtn.png"));
	ComponentPtr quitBtnMouseInput(new MouseInputComp());
	ComponentPtr quitBtnButtonInput(new ButtonComp());
	ComponentPtr quitBtnScript(new QuitButtonScript());

	std::shared_ptr<GameObject> m_quitBtn(new GameObject("quitBtn"));

	m_quitBtn->addComponent(quitBtnTransform);
	m_quitBtn->addComponent(quitBtnTexture);
	m_quitBtn->addComponent(quitBtnMouseInput);
	m_quitBtn->addComponent(quitBtnButtonInput);
	m_quitBtn->addComponent(quitBtnScript);
	m_quitBtn->getComponent<QuitButtonScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_quitBtn->m_renderer = m_renderer;
	m_quitBtn->m_input = m_input;

	m_gameObjectFactory->addPrototype(m_quitBtn);

	//create gameobjects
	std::shared_ptr<IPrototype> gameObjectClone;
	gameObjectClone = m_gameObjectFactory->create("playBtn");
	std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);

	gameObjectClone = m_gameObjectFactory->create("quitBtn");
	gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);
}

void MainMenuState::onUpdate(float deltaTime)
{
	if (m_active)
	{
		for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
		{
			(*it)->update(deltaTime);
			++it;
		}
	}
}

void MainMenuState::onDraw()
{
	if (m_active)
	{
		for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
		{
			(*it)->draw();
			++it;
		}
	}
}

void MainMenuState::onPopped()
{

}

MainMenuState::~MainMenuState()
{
}