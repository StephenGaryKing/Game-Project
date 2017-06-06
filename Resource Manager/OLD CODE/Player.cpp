#include "Player.h"
//#include "Animation.h"


Player::Player(Matrix3 transform, std::shared_ptr<ResourceBase> texture, std::vector<Vector3> points)
{
	m_transform = transform;
	m_texture = texture;
	m_points = points;
	/*
	m_size = Vector3((float)texture->getWidth()/2, (float)texture->getHeight()/2, 0.0f);

	// initialize the list of images that are shown when the player is hit
	m_explosionAnimation[0] = new aie::Texture("./textures/explosion/explosion1.png");
	m_explosionAnimation[1] = new aie::Texture("./textures/explosion/explosion2.png");
	m_explosionAnimation[2] = new aie::Texture("./textures/explosion/explosion3.png");
	m_explosionAnimation[3] = new aie::Texture("./textures/explosion/explosion4.png");
	m_explosionAnimation[4] = new aie::Texture("./textures/explosion/explosion5.png");
	m_explosionAnimation[5] = new aie::Texture("./textures/explosion/explosion6.png");
	m_explosionAnimation[6] = new aie::Texture("./textures/explosion/explosion7.png");
	m_explosionAnimation[7] = new aie::Texture("./textures/explosion/explosion8.png");

	// initialize the list of images that are shown when the player spawns
	m_spawnAnimation[0] = new aie::Texture("./textures/spawn/spawn1.png");
	m_spawnAnimation[1] = new aie::Texture("./textures/spawn/spawn2.png");
	m_spawnAnimation[2] = new aie::Texture("./textures/spawn/spawn3.png");
	m_spawnAnimation[3] = new aie::Texture("./textures/spawn/spawn4.png");
	m_spawnAnimation[4] = new aie::Texture("./textures/spawn/spawn5.png");
	m_spawnAnimation[5] = new aie::Texture("./textures/spawn/spawn6.png");
	m_spawnAnimation[6] = new aie::Texture("./textures/spawn/spawn7.png");
	m_spawnAnimation[7] = new aie::Texture("./textures/spawn/spawn8.png");
	m_spawnAnimation[8] = new aie::Texture("./textures/spawn/spawn9.png");
	m_spawnAnimation[9] = new aie::Texture("./textures/spawn/spawn10.png");
	m_spawnAnimation[10] = new aie::Texture("./textures/spawn/spawn11.png");
	m_spawnAnimation[11] = new aie::Texture("./textures/spawn/spawn12.png");
	m_spawnAnimation[12] = new aie::Texture("./textures/spawn/spawn13.png");
	m_spawnAnimation[13] = new aie::Texture("./textures/spawn/spawn14.png");
	m_spawnAnimation[14] = new aie::Texture("./textures/spawn/spawn15.png");
	m_spawnAnimation[15] = new aie::Texture("./textures/spawn/spawn16.png");
	*/
}

void Player::Update(float deltaTime, aie::Input* input)
{
	if (m_enabled && ! m_dead)
	{
		m_transform[2].x = (float)input->getMouseX();
		m_transform[2].y = (float)input->getMouseY();
	}
	if (m_enabled && m_dead)
	{
		if (m_timePassed >= m_respawnTime)
		{
			m_dead = false;
			m_timePassed = 0;
		}
	}

	if (m_dead)
	{
		m_timePassed += deltaTime;
		if (m_timePassed >= m_deathTime && m_dead)
		{
			m_transform[2].x = (float)input->getMouseX();
			m_transform[2].y = (float)input->getMouseY();
			Respawn();
		}
	}
}

void Player::Draw(aie::Renderer2D* renderer)
{
	if (m_enabled && ! m_dead)
	{
		renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
		renderer->drawSpriteTransformed3x3(m_texture->as<aie::Texture>(), m_transform);
	}
	for (int i = 0; i < (int)m_children.size(); i++)
	{
		// draw the children of this GameObject
		m_children[i]->Draw(renderer);
	}
}

void Player::HandleCollision(GameObject* other, Hit hit)
{
	if (!m_dead)
	{
		HandleCollision(hit);
		other->HandleCollision(hit);
	}
}

void Player::HandleCollision(Hit hit)
{
	//m_children.push_back(new Animation(m_transform, m_explosionAnimation, 8, this));
	m_enabled = false;
	m_dead = true;
}

void Player::Respawn()
{
	m_enabled = true;
	//m_children.push_back(new Animation(m_transform, m_spawnAnimation, 16, this));
	m_timePassed = 0;
}


Player::~Player()
{
}
