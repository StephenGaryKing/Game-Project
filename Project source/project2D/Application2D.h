#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GameObject.h"
#include "Tank.h"
#include "Input.h"

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

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture[10];
	aie::Font*			m_font;
	
	GameObject**		m_players;
	GameObject**		m_planes;
	Matrix3**			m_spawnLocations;
	int					m_amountOfPlayers = 2;
	int					m_amountOfPlanes = 4;
	int					m_amountOfShells = 4;

	float m_cameraX, m_cameraY;
	float m_timer;
};