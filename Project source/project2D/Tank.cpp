#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank(Matrix3 trans, aie::Texture* tex, aie::Texture* turretTex, int shellAmount, int leftK, int rightK, int upK, int downK, int fireK)
	: GameObject(trans, tex, { Vector3{ (float)tex->getWidth() / 2,(float)tex->getHeight() / 2,1 } , Vector3{ (float)tex->getWidth() / 2,-(float)tex->getHeight() / 2,1 } , Vector3{ -(float)tex->getWidth() / 2,-(float)tex->getHeight() / 2,1 } , Vector3{ -(float)tex->getWidth() / 2,(float)tex->getHeight() / 2,1 } })
{
	// initialize the list of images that are shown when the tank is hit
	explosionAnimation[0] = new aie::Texture("./textures/explosion/explosion1.png");
	explosionAnimation[1] = new aie::Texture("./textures/explosion/explosion2.png");
	explosionAnimation[2] = new aie::Texture("./textures/explosion/explosion3.png");
	explosionAnimation[3] = new aie::Texture("./textures/explosion/explosion4.png");
	explosionAnimation[4] = new aie::Texture("./textures/explosion/explosion5.png");
	explosionAnimation[5] = new aie::Texture("./textures/explosion/explosion6.png");
	explosionAnimation[6] = new aie::Texture("./textures/explosion/explosion7.png");
	explosionAnimation[7] = new aie::Texture("./textures/explosion/explosion8.png");

	spawnLocation = transform;	// the tank returns here when it is hit
	listOfShells = new GameObject*[shellAmount];

	for (int i = 0; i < shellAmount; i++)
	{
		// populate the list of shells with the appropriate amount of shells
		listOfShells[i] = new Shell({}, shellTexture , this);
	}

	amountOfShells = shellAmount;
	// set the controlls to the specified keys
	leftKey = leftK;
	rightKey = rightK;
	upKey = upK;
	downKey = downK;
	fireKey = fireK;

	turretTexture = turretTex;
	// add a empty game object to store the turret's rotation relative to the tank
	children.push_back(new GameObject({ 1,0,0,0,1,0,0,0,1 }, nullptr, {}));
	children[0]->parent = this;
	// add a game object to display the turret
	children[0]->children.push_back(new GameObject({ 1,0,0,0,1,0,0,20,1 }, turretTexture, { Vector3{ (float)turretTexture->getWidth() / 2,(float)turretTexture->getHeight() / 2,1 } , Vector3{ (float)turretTexture->getWidth() / 2,-(float)turretTexture->getHeight() / 2,1 } , Vector3{ -(float)turretTexture->getWidth() / 2,-(float)turretTexture->getHeight() / 2,1 } , Vector3{ -(float)turretTexture->getWidth() / 2,(float)turretTexture->getHeight() / 2,1 } }));
	children[0]->children[0]->parent = children[0];
}

void Tank::Update(float dt, aie::Input* input)
{
	deltaTime = dt;

	// handle the inputs of the user to move and rotate the tank and the tank's turret
	if (input->isKeyDown(leftKey))
	{
		// move and rotate the Tank
		GameObject::TranslateGameObject({ 0,movementSpeed * deltaTime,1 });
		GameObject::RotateGameObject(rotationSpeed * deltaTime);
	}
	if (input->isKeyDown(rightKey))
	{
		// move and rotate the Tank
		GameObject::TranslateGameObject({ 0,movementSpeed * deltaTime,1 });
		GameObject::RotateGameObject(-rotationSpeed * deltaTime);
	}

	if (input->isKeyDown(upKey))
	{
		// rotate the turret
		children[0]->RotateGameObject(rotationSpeed * deltaTime);
	}

	if (input->isKeyDown(downKey))
	{
		// rotate the turret
		children[0]->RotateGameObject(-rotationSpeed * deltaTime);
	}

	if (input->wasKeyPressed(fireKey))
	{
		Fire();
	}

	// update the shells that belong to this tank
	for (int i = 0; i < amountOfShells; i++)
	{
		listOfShells[i]->Update(deltaTime, input);
	}

	GameObject::Update(deltaTime, input);
}

void Tank::UpdateCollisions(GameObject* listOfGameObjects[], int amountOfGameObjects)
{
	// Update the collisions for this tank
	GameObject::UpdateCollisions(listOfGameObjects, amountOfGameObjects);

	for (int i = 0; i < amountOfGameObjects; i++)
	{
		if (listOfGameObjects[i] != this)
		{
			listOfGameObjects[i]->UpdateCollisions(listOfShells, amountOfShells);
		}
	}
	for (int i = 0; i < amountOfShells; i++)
	{
		listOfShells[i]->UpdateCollisions(listOfGameObjects, amountOfGameObjects);
	}
}

void Tank::Draw(aie::Renderer2D* renderer)
{
	//draw this tank
	GameObject::Draw(renderer);

	//draw the shells that belong to this tank
	for (int i = 0; i < amountOfShells; i++)
	{
		listOfShells[i]->Draw(renderer);
	}
}

void Tank::HandleCollision(GameObject* other, Hit hit)
{
	// execute the correct code for each GameObject that is involved in the collision
	HandleCollision(hit);
	other->HandleCollision(hit);
}

void Tank::HandleCollision(Hit hit)
{
	// create an explosion animation at the Tank's position
	Matrix3 position;
	position = transform;
	children.push_back(new Animation(position, explosionAnimation, 8, this));
	// change the scale of the explosion to be twice as large
	children[(int)children.size() - 1]->ScaleGameObject({2,2,1});
	// put the Tank back where it spawned (with the correct rotation)
	transform = spawnLocation;
}

void Tank::Fire()
{
	static int currentShellToMove = 0; 	// current shell to move is the number of the shell that is will be shot
	Matrix3 positionToSpawn;
	Matrix3 offset = { 1,0,0,0,1,0,0,(float)turretTexture->getHeight() / 2,1 }; // this is applied to the shell so that it spawns at the end of the tank's barrel
	positionToSpawn = positionToSpawn * transform * children[0]->transform *offset; // apply the transforms in the correct order
	listOfShells[currentShellToMove]->transform = positionToSpawn;
	listOfShells[currentShellToMove]->enabled = true; // enabling the shell alows it to move, collide and be drawn
	currentShellToMove++;
	// if the currentShellToMove is too high cycle back to the start of the list
	if (currentShellToMove > amountOfShells - 1)
		currentShellToMove = 0;
}

Tank::~Tank()
{
}