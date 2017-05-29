#include "Shell.h"

Shell::Shell()
{
}

Shell::Shell(Matrix3 trans, aie::Texture* tex, GameObject* c)
	: GameObject(trans, tex, { trans[2] })
{
	enabled = false; // do not display or update the shell until it is fired
	creator = c;

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

void Shell::Update(float dt, aie::Input* input)
{
	if (enabled)
	{
		deltaTime = dt;
		//move the Shell upward in it's local space
		TranslateGameObject({ 0, velocity * deltaTime, 1 });
		GameObject::Update(deltaTime, input);
	}
}

void Shell::Draw(aie::Renderer2D* renderer)
{
	if (enabled)
	{
		GameObject::Draw(renderer);
	}
	for (int i = 0; i < (int)children.size(); i++)
	{
		// draw the children of this GameObject
		children[i]->Draw(renderer);
	}
}

void Shell::HandleCollision(GameObject* other, Hit hit)
{
	if (enabled)
	{
		// if the other GameObject is not the tank that created this
		if (other != creator)
		{
			// execute the correct code for each GameObject that is involved in the collision
			HandleCollision(hit);
			other->HandleCollision(hit);
		}
	}
}

void Shell::HandleCollision(Hit hit)
{
	//create an explosion at the point of contact
	Matrix3 position;
	position[2] = hit.point;
	children.push_back(new Animation(position, explosionAnimation, 8, this));
	// move the shell to the origin and dissable it
	transform = {};
	enabled = false;
}

Shell::~Shell()
{
}