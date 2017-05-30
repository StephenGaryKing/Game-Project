#include "Player.h"
#include "Animation.h"


Player::Player(Matrix3 transform, aie::Texture* texture, std::vector<Vector3> points)
{
	m_transform = transform;
	m_texture = texture;
	m_points = points;

	m_size = Vector3((float)texture->getWidth(), (float)texture->getHeight(), 0.0f);

	// initialize the list of images that are shown when the tank is hit
	explosionAnimation[0] = new aie::Texture("./textures/explosion/explosion1.png");
	explosionAnimation[1] = new aie::Texture("./textures/explosion/explosion2.png");
	explosionAnimation[2] = new aie::Texture("./textures/explosion/explosion3.png");
	explosionAnimation[3] = new aie::Texture("./textures/explosion/explosion4.png");
	explosionAnimation[4] = new aie::Texture("./textures/explosion/explosion5.png");
	explosionAnimation[5] = new aie::Texture("./textures/explosion/explosion6.png");
	explosionAnimation[6] = new aie::Texture("./textures/explosion/explosion7.png");
	explosionAnimation[7] = new aie::Texture("./textures/explosion/explosion8.png");
}

void Player::Update(float deltaTime, aie::Input* input)
{
	m_transform[2].x = (float)input->getMouseX();
	m_transform[2].y = (float)input->getMouseY();
}

void Player::Draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->drawSpriteTransformed3x3(m_texture, m_transform);
	for (int i = 0; i < (int)m_children.size(); i++)
	{
		// draw the children of this GameObject
		m_children[i]->Draw(renderer);
	}
}

void Player::HandleCollision(GameObject* other, Hit hit)
{
	HandleCollision(hit);
	other->HandleCollision(hit);
}

void Player::HandleCollision(Hit hit)
{
	m_children.push_back(new Animation(m_transform, explosionAnimation, 8, this));
	// change the scale of the explosion to be twice as large
	//m_children[(int)m_children.size() - 1]->ScaleGameObject({ 2,2,1 });
}


Player::~Player()
{
}
