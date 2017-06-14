#include "States.h"
#include "ComponentList.h"
#include "GameStateManager.h"

SplashScreenState::SplashScreenState()
{
}

void SplashScreenState::onEnter()
{
	ComponentPtr splashTransform(new TransformComp(Vector3(200, 400, 1), Vector3(0,0,0)));
	ComponentPtr splashAnimation(new AnimationComp("./textures/splashAnimation/", 4));
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

	if (m_timer >= 5)
		m_gameStateManager->popState();
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