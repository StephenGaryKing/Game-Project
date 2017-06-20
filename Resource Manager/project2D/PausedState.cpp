#include "States.h"
#include "GameStateManager.h"
<<<<<<< HEAD
#include "MenuButtonScript.h"
=======
>>>>>>> origin/master

PausedState::PausedState()
{
}

void PausedState::onEnter()
{
	if (m_gameObjects.size() == 0)
		createGameObjects();
}

void PausedState::createGameObjects()
{
	ComponentPtr menuBtnTransform(new TransformComp(Vector3((float)m_gameStateManager->m_application->getWindowWidth() / 2, (float)m_gameStateManager->m_application->getWindowHeight() / 10 * 6, 1), Vector3(0, 0, 0), 2));
	ComponentPtr menuBtnTexture(new TextureComp("./textures/menuBtn.png"));
	ComponentPtr menuBtnMouseInput(new MouseInputComp());
	ComponentPtr menuBtnButtonInput(new ButtonComp());
	ComponentPtr menuBtnScript(new MenuButtonScript());

	std::shared_ptr<GameObject> m_menuBtn(new GameObject("menuBtn"));

	m_menuBtn->addComponent(menuBtnTransform);
	m_menuBtn->addComponent(menuBtnTexture);
	m_menuBtn->addComponent(menuBtnMouseInput);
	m_menuBtn->addComponent(menuBtnButtonInput);
	m_menuBtn->addComponent(menuBtnScript);
	m_menuBtn->getComponent<MenuButtonScript>(SCRIPT)->m_gameStateManager = m_gameStateManager;
	m_menuBtn->m_renderer = m_renderer;
	m_menuBtn->m_input = m_input;

	m_gameObjectFactory->addPrototype(m_menuBtn);



	std::shared_ptr<IPrototype> gameObjectClone = m_gameObjectFactory->create("quitBtn");
	std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);

	gameObjectClone = m_gameObjectFactory->create("menuBtn");
	gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);
}

void PausedState::onUpdate(float deltaTime)
{
<<<<<<< HEAD
	if (m_input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_gameStateManager->popState();
	}

	if (m_input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		m_gameStateManager->popDownTo((int)eGameState::MENU);
	}
=======
	if (m_input->wasKeyReleased(aie::INPUT_KEY_SPACE))
	{
		m_gameStateManager->popState();
	}
}

void PausedState::createGameObjects()
{
>>>>>>> origin/master

	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->update(deltaTime);
		++it;
	}
}

void PausedState::onDraw()
{
	m_renderer->drawBox(
		m_gameStateManager->m_application->getWindowWidth() / 2.0f,
		m_gameStateManager->m_application->getWindowHeight() / 2.0f,
		m_gameStateManager->m_application->getWindowWidth() / 2.0f,
		m_gameStateManager->m_application->getWindowHeight() / 2.0f);
<<<<<<< HEAD

	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->draw();
		++it;
	}
=======
>>>>>>> origin/master
}

PausedState::~PausedState()
{
}