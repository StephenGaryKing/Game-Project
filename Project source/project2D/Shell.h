#pragma once
#include "GameObject.h"
#include "Animation.h"
class Shell :
	public GameObject
{
public:
	// constructors
	Shell();
	Shell(Matrix3 trans, aie::Texture* tex, GameObject* creator);
	// update and draw the shell
	void Update(float dt, aie::Input* input);
	void Draw(aie::Renderer2D* renderer);
	void HandleCollision(GameObject* other, Hit hit);
	void HandleCollision(Hit hit);
	// deconstructor
	~Shell();

private:
	GameObject* creator;
	aie::Texture* explosionAnimation[8];

	float velocity = 1000;	// the speed that the shell moves
	float deltaTime;
};