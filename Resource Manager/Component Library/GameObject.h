#pragma once
#include "Matrix3.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Input.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "IPrototype.h"
#include <glm\glm\vec2.hpp>

typedef std::shared_ptr<Resource<aie::Texture>> TexturePtr;

struct Hit
{
	bool hitting = false;
	Vector3 point;
	Vector3 vec;
};

class GameObject : public IPrototype
{
public:
	GameObject(const std::string name, std::shared_ptr<ResourceBase> texture);
	GameObject(const std::string name, const char* filename);
	GameObject(const GameObject& other);
	~GameObject();
	
	GameObject& operator=(const GameObject& other);

	virtual std::shared_ptr<IPrototype> clone();
	virtual std::string getName() { return m_name; }

	bool isEnabled() { return m_enabled; }
	glm::vec2 getPosition() { return m_position; }
	void setEnabled(bool state) { m_enabled = state; }
	void setVelocity(float x, float y);
	void setPosition(float x, float y);

	void Update(float deltaTime, aie::Input* input);
	void draw(aie::Renderer2D* renderer);

private:
	std::shared_ptr<ResourceBase> m_texture;
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	bool m_enabled;
	std::string m_name;
	

};










/*


	//constructors
	GameObject();
	GameObject(Matrix3 transform, TexturePtr texture, std::vector<Vector3> points);
	//GameObject Movement
	void RotateGameObject(float angle);
	void ScaleGameObject(Vector3 scale);
	void TranslateGameObject(Vector3 displacement);
	// update and draw the GameObject
	virtual void Update(float deltaTime, aie::Input* input);
	virtual void UpdateCollisions(GameObject* listOfGameObjects[], int amountOfGameObjects);
	virtual void Draw(aie::Renderer2D* renderer);
	virtual void HandleCollision(GameObject* other, Hit hit);
	virtual void HandleCollision(GameObject* other);
	virtual void HandleCollision(Hit hit);
	bool IsColliding(GameObject* other);

	//collisions
	Hit BroadPhaseCollision(GameObject* other);

	Hit PlaneBox(GameObject* other);
	Hit BoxBoxCollision(GameObject* other);
	Hit BoxCircleCollision(GameObject* other);
	Hit CircleBoxCollision(GameObject* other);
	Hit CircleCircleCollision(GameObject* other);

	// deconstructor
	~GameObject();

	bool m_enabled = true; // this determines if this GameObject should calculate collisions and be drawn
	Matrix3 m_transform;
	std::shared_ptr<ResourceBase> m_texture;
	GameObject* m_parent = nullptr;
	std::vector<GameObject*> m_children;
	std::vector<Vector3> m_points;

	float m_currentRotation = 0;
	Vector3 m_size;
	Vector3 m_min;
	Vector3 m_max;
};

*/