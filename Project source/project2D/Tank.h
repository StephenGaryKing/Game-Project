#pragma once

#include "GameObject.h"
#include "Shell.h"

class Tank :
	public GameObject
{
public:
	// constructors
	Tank();
	Tank(Matrix3 mat, aie::Texture* tex, aie::Texture* turretTex, int amountOfShells, int leftK, int rightK, int upK, int downK, int fireK);
	// update and draw Tank
	void Update(float dt, aie::Input* input);
	void UpdateCollisions(GameObject* listOfGameObjects[], int amountOfGameObjects);
	void Draw(aie::Renderer2D* renderer);
	void HandleCollision(GameObject* other, Hit hit);
	void HandleCollision(Hit hit);
	// spawn a shell at the barrel of the turret
	void Fire();
	//deconstructor
	~Tank();

private:
	Matrix3 spawnLocation;

	aie::Texture* explosionAnimation[8];

	aie::Texture* turretTexture;
	aie::Texture* shellTexture = new aie::Texture("./textures/shell.png");

	GameObject** listOfShells;
	int amountOfShells;

	int leftKey, rightKey, upKey, downKey, fireKey;
	float movementSpeed = 100;
	float rotationSpeed = 1;
	float deltaTime;
};