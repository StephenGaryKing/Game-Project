#include "Application2D.h"
#include "Texture.h"
#include "Font.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {
	for (int i = 0; i < m_amountOfPlanes; i++)
	{
		delete m_planes[i];
	}
	for (int i = 0; i < m_amountOfPlayers; i++)
	{
		delete m_players[i];
	}
	for (int i = 0; i < m_amountOfPlayers; i++)
	{
		delete m_spawnLocations[i];
	}
	for (int i = 0; i < 4; i++)
	{
		m_texture[i];
	}
}

bool Application2D::startup() {
	
	setBackgroundColour(0.7f, 0.7f, 0.7f, 1);

	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	//create planes for the walls
	//local points are used to store {slope x, slope y, distance from origin}
	m_planes = new GameObject*[m_amountOfPlanes];
	m_planes[0] = new GameObject({}, nullptr, { { 1, 0, 0 }, {} });
	m_planes[1] = new GameObject({}, nullptr, { { 0, 1, 35.3f }, {} });
	m_planes[2] = new GameObject({}, nullptr, { { -1, 0, 26.3f },{} });
	m_planes[3] = new GameObject({}, nullptr, { { 0, -1, 0 }, {} });


	//initialize player data
	m_players = new GameObject*[m_amountOfPlayers];
	m_texture[0] = new aie::Texture("./textures/tankRed.png");
	m_texture[1] = new aie::Texture("./textures/barrelRed.png");
	m_texture[2] = new aie::Texture("./textures/tankBlue.png");
	m_texture[3] = new aie::Texture("./textures/barrelBlue.png");

	m_spawnLocations = new Matrix3*[m_amountOfPlayers];
	m_spawnLocations[0] = new Matrix3();
	*(m_spawnLocations[0]) = Matrix3(1, 0, 0, 0, 1, 0, (float)m_texture[0]->getWidth(), (float)m_texture[0]->getHeight(), 1);
	m_spawnLocations[0]->setRotateZ(-0.785398);
	m_spawnLocations[1] = new Matrix3();
	*(m_spawnLocations[1]) = Matrix3( 1,0,0,0,1,0,(float)getWindowWidth() - (float)m_texture[2]->getWidth(),(float)getWindowHeight() - (float)m_texture[2]->getHeight(),1 );
	m_spawnLocations[1]->setRotateZ(-3.92699);
	
	m_players[0] = new Tank(*(m_spawnLocations[0]), m_texture[0], m_texture[1], m_amountOfShells, aie::INPUT_KEY_A, aie::INPUT_KEY_D, aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_LEFT_CONTROL);
	m_players[1] = new Tank(*(m_spawnLocations[1]), m_texture[2], m_texture[3], m_amountOfShells, aie::INPUT_KEY_LEFT, aie::INPUT_KEY_RIGHT, aie::INPUT_KEY_UP, aie::INPUT_KEY_DOWN, aie::INPUT_KEY_RIGHT_CONTROL);

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

	// input
	aie::Input* input = aie::Input::getInstance();
	
	//update players and their gameObjects
	for (int i = 0; i < m_amountOfPlayers; i++)
	{
		if (m_players[i] != nullptr)
		{
			m_players[i]->Update(deltaTime, input);
			m_players[i]->UpdateCollisions(m_players, m_amountOfPlayers);
			for (int j = 0; j < m_amountOfPlanes; j++)
			{
				m_planes[j]->UpdateCollisions(m_players, m_amountOfPlayers);
			}
		}
	}
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	
	//draw boxes
	for (int i = 0; i < m_amountOfPlayers; i++)
	{
		if (m_players[i]->texture != nullptr)
			m_players[i]->Draw(m_2dRenderer);
	}
	
	// done drawing sprites

	//draw FPS
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	m_2dRenderer->end();
}