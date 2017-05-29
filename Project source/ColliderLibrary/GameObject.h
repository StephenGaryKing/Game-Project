#pragma once
#include "Matrix3.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Input.h"

struct Hit
{
	bool hitting = false;
	Vector3 point;
	Vector3 vec;
};

class GameObject
{
public:
	//constructors
	GameObject();
	GameObject(Matrix3 trans, aie::Texture* tex, std::vector<Vector3> points);
	//GameObject Movement
	void RotateGameObject(float angle);
	void ScaleGameObject(Vector3 scale);
	void TranslateGameObject(Vector3 displacement);
	// update and draw the GameObject
	virtual void Update(float deltaTime, aie::Input* input);
	virtual void UpdateCollisions(GameObject* listOfGameObjects[], int amountOfGameObjects);
	virtual void Draw(aie::Renderer2D* renderer);
	virtual void HandleCollision(GameObject* other, Hit hit);
	virtual void HandleCollision(Hit hit);

	//collisions
	Hit BroadPhaseCollision(GameObject* other);

	Hit PlaneBox(GameObject* other);
	Hit BoxBoxCollision(GameObject* other);
	Hit BoxCircleCollision(GameObject* other);
	Hit CircleBoxCollision(GameObject* other);
	Hit CircleCircleCollision(GameObject* other);

	// deconstructor
	~GameObject();

	bool enabled = true; // this determines if this GameObject should calculate collisions and be drawn
	Matrix3 transform;
	aie::Texture* texture;
	GameObject* parent = nullptr;
	std::vector<GameObject*> children;
	std::vector<Vector3> localPoints;

	float currentRotation = 0;
	Vector3 size;
	Vector3 min;
	Vector3 max;
};

