#include "States.h"
#include "ComponentList.h"
#include "GameStateManager.h"

SplashScreenState::SplashScreenState()
{
}

void SplashScreenState::onPushed()
{
	if (m_gameObjects.size() == 0)
		createGameObjects();
}

void SplashScreenState::createGameObjects()
{
	ComponentPtr splashTransform(new TransformComp(Vector3((float)m_gameStateManager->m_application->getWindowWidth() / 2, (float)m_gameStateManager->m_application->getWindowHeight() / 2, 1), Vector3(0, 0, 0), 10));
	ComponentPtr splashAnimation(new AnimationComp("./textures/splashAnimation/", 36, 20));
	std::dynamic_pointer_cast<AnimationComp>(splashAnimation)->m_looping = true;

	std::shared_ptr<GameObject> m_splash(new GameObject("splash"));

	m_splash->addComponent(splashTransform);
	m_splash->addComponent(splashAnimation);
	m_splash->m_renderer = m_renderer;

	m_gameObjectFactory->addPrototype(m_splash);

	std::shared_ptr<IPrototype> gameObjectClone;
	gameObjectClone = m_gameObjectFactory->create("splash");
	std::shared_ptr<GameObject> gameObject = std::dynamic_pointer_cast<GameObject>(gameObjectClone);
	m_gameObjects.push_back(gameObject);
}

void SplashScreenState::onUpdate(float deltaTime)
{
	m_timer += deltaTime;

	if (m_input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		m_timer = 0;
		m_gameStateManager->popState();
	}

	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->update(deltaTime);
		++it;
	}

	if (m_timer >= m_timeToWait)
	{
		m_timer = 0;
		m_gameStateManager->popState();
	}
		
}

void SplashScreenState::onDraw()
{
	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); )
	{
		(*it)->draw();
		++it;
	}
}

void SplashScreenState::onPopped()
{
	m_gameStateManager->pushState((int)eGameState::MENU);
}

SplashScreenState::~SplashScreenState()
{
}