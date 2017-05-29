#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GameObject.h"
#include "Input.h"
#include "GameStateManager.h"

enum class eGameState
{
	MENU,
	INGAME,
	PAUSE,
	STATE_COUNT
};

class Application2D : public aie::Application {

public:
	// constructor
	Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	// deconstructor
	virtual ~Application2D();

protected:

	aie::Input*			m_input;
	GameStateManager*	m_gameStateManager;
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture[10];
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
};