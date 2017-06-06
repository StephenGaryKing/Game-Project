#include "GameObject.h"

GameObject::GameObject(const std::string name, std::shared_ptr<ResourceBase> texture) :
	m_name(name), m_texture(texture), m_position(glm::vec2(0, 0)),
	m_velocity(glm::vec2(0, 0))
{}

GameObject::GameObject(const std::string name, const char* filename) :
	m_name(name), m_position(glm::vec2(0, 0)), m_velocity(glm::vec2(0, 0))
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

GameObject::GameObject(const GameObject& other)
{
	m_texture = other.m_texture; 
	m_position = other.m_position; 
	m_velocity = other.m_velocity; 
	m_name = other.m_name;
}

GameObject::~GameObject()
{
	std::cout << m_name << "deallocated" << std::endl;
}

GameObject& GameObject::operator=(const GameObject& other)
{
	m_texture = other.m_texture; 
	m_position = other.m_position; 
	m_velocity = other.m_velocity; 
	m_name = other.m_name; 
	return *this;
}

std::shared_ptr<IPrototype> GameObject::clone()
{
	return std::shared_ptr<IPrototype>(new GameObject(*this));
}

void GameObject::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void GameObject::setVelocity(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
}

void GameObject::Update(float deltaTime, aie::Input* input)
{
	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
}

void GameObject::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}




/*
GameObject::GameObject()
{
}

GameObject::GameObject(Matrix3 transform, TexturePtr texture, std::vector<Vector3> points)
{
	
	// set the position, rotation, and texture to the values given
	m_transform = transform;
	m_texture = texture;
	// if there is a texture provided set the half extents in x and y equal to half the width and height of the texture
	if (m_texture != nullptr)
		m_size = { (float)m_texture->getWidth() / 2, (float)m_texture->getHeight() / 2, 1 };
	// initialize the points that will be used to for collisions
	for (int i = 0; i < (int)points.size(); i++)
	{
		m_points.push_back(points[i]);
	}

}

void GameObject::RotateGameObject(float angle)
{
	// create a matrix to rotate the game object
	Matrix3 rotationMatrix;
	m_currentRotation = angle;
	rotationMatrix.setRotateZ(angle);
	// apply rotation matrix
	m_transform = m_transform * rotationMatrix;
}

void GameObject::ScaleGameObject(Vector3 scale)
{
	// enlarge the GameObject by (scale.x, scale.y, scale.z)
	m_transform[0] = m_transform[0] * scale;
	m_transform[1] = m_transform[1] * scale;
}

void GameObject::TranslateGameObject(Vector3 displacement)
{
	// move the GameObject by (displacement.x, displacement.y, displacement.z) relative to its current position
	Matrix3 displacementMatrix;
	displacementMatrix[2] = displacement;
	m_transform = m_transform * displacementMatrix;
}

void GameObject::Draw(aie::Renderer2D* renderer)
{
	// if GameObject has a texture to draw
	if (m_texture != nullptr)
	{
		Matrix3 positionToDraw;
		GameObject* lastParent = nullptr;
		GameObject* currentParent = m_parent;
		// loop through the hierachy of this GameObject from parent to child to ditermine the correct order to apply transformations
		while (lastParent != m_parent)
		{
			while (currentParent->m_parent != lastParent)
			{
				currentParent = currentParent->m_parent;
			}
			// apply the current parent's position and rotation to the current position to draw
			positionToDraw = positionToDraw * currentParent->m_transform;
			lastParent = currentParent;
			currentParent = m_parent;
		}
		// add the local position and rotation to the current position to draw
		positionToDraw = positionToDraw * m_transform;
		// draw the GameObject using its texture
		//renderer->drawSpriteTransformed3x3(m_texture, positionToDraw);

		// draw Debug lines
		if ((int)m_points.size() == 1)
		{
			renderer->setRenderColour(1.0f, 1.0f, 1.0f, 0.5f);
			renderer->drawCircle(m_transform[2].x, m_transform[2].y, m_size.x);
			renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
		}
		renderer->drawLine(m_min.x, m_min.y, m_max.x, m_min.y);
		renderer->drawLine(m_max.x, m_min.y, m_max.x, m_max.y);
		renderer->drawLine(m_max.x, m_max.y, m_min.x, m_max.y);
		renderer->drawLine(m_min.x, m_max.y, m_min.x, m_min.y);
	}
	for (int i = 0; i < (int)m_children.size(); i++)
	{
		// draw the children of this GameObject
		m_children[i]->Draw(renderer);
	}
}

void GameObject::Update(float deltaTime, aie::Input* input)
{
	// update the min and max points of this GameObject
	if ((int)m_points.size() > 0)
	{
		Matrix3 globalPosition;
		GameObject* lastParent = nullptr;
		GameObject* currentParent = m_parent;
		while (lastParent != m_parent)
			{
				while (currentParent->m_parent != lastParent)
				{
					currentParent = currentParent->m_parent;
				}
				globalPosition = globalPosition * currentParent->m_transform;
				lastParent = currentParent;
				currentParent = m_parent;
			}
		globalPosition = globalPosition * m_transform;
		m_min = globalPosition * m_points[0];
		m_max = globalPosition * m_points[0];
		for (int i = 0; i < (int)m_points.size(); i++)
		{
			if (m_min.x > (globalPosition * m_points[i]).x)
				m_min.x = (globalPosition * m_points[i]).x;
			if (m_min.y > (globalPosition * m_points[i]).y)
				m_min.y = (globalPosition * m_points[i]).y;
			if (m_max.x < (globalPosition * m_points[i]).x)
				m_max.x = (globalPosition * m_points[i]).x;
			if (m_max.y < (globalPosition * m_points[i]).y)
				m_max.y = (globalPosition * m_points[i]).y;
		}
	}
	for (int i = 0; i < (int)m_children.size(); i++)
	{
		// update the min and max points of this GameObject's children
		m_children[i]->Update(deltaTime, input);
	}
}

void GameObject::UpdateCollisions(GameObject* listOfGameObjects[], int amountOfGameObjects)
{
	for (int i = 0; i < amountOfGameObjects; i++)
	{
		// if the game object to collide with is different from this
		if (listOfGameObjects[i] != this)
		{
			// perform a broadphase collision test between the two GameObjects
			Hit hit = BroadPhaseCollision(listOfGameObjects[i]);
			if (hit.hitting)
			{
				HandleCollision(listOfGameObjects[i], hit);
			}
		}
	}
}

bool GameObject::IsColliding(GameObject* other)
{
	if (m_enabled && other->m_enabled)
	{
		Hit hit = BroadPhaseCollision(other);
		if (hit.hitting)
			return true;
	}
	return false;
}

void GameObject::HandleCollision(GameObject* other)
{
	Hit hit;
	hit.hitting = true;
	HandleCollision(other, hit);
}

void GameObject::HandleCollision(GameObject* other, Hit hit)
{
	if (m_enabled)
	{
		// handle the collision of this game object and the other game object
		HandleCollision(hit);
		other->HandleCollision(hit);
	}
}

void GameObject::HandleCollision(Hit hit)
{
}

Hit GameObject::BroadPhaseCollision(GameObject* other)
{
	Hit hit;
	//if the other GameObject is a box
	if ((int)other->m_points.size() == 4)
	{
		//if this is a plane
		if ((int)m_points.size() == 2)
		{
			return PlaneBox(other);
		}
		//if this is a box
		if ((int)m_points.size() == 4)
		{
			return BoxBoxCollision(other);
		}
		//if this is a circle
		if ((int)m_points.size() == 1)
		{
			return CircleBoxCollision(other);
		}
		return hit;
	}
	//if the other GameObject is a circle
	if ((int)other->m_points.size() == 1)
	{
		//if this is a box
		if ((int)m_points.size() == 4)
		{
			return CircleBoxCollision(other);
		}
		//if this is a circle
		if ((int)m_points.size() == 1)
		{
			return CircleCircleCollision(other);
		}
		return hit;
	}
	return hit;
}

Hit GameObject::PlaneBox(GameObject* other)
{
	// perform a plane Vs point test for each point in the game object's collider
	Hit hit;
	Vector3 normal;
	normal = m_points[0].GetNormalised();
	normal = Vector3(-normal.y, normal.x, 1);
	for (int i = 0; i < (int)other->m_points.size(); i++)
	{
		float side = (other->m_transform * other->m_points[i]).dot(normal);
		side += m_points[0].z;
		if (side < 0)
		{
			// return early if a point is on the other side of the plane
			hit.hitting = true;
			return hit;
		}
	}
	return hit;
}

Hit GameObject::BoxBoxCollision(GameObject* other)
{
	Hit hit;
	// compare the max and min of each GameObject to ditermine if there is an overlap
	if (m_max.x < other->m_min.x)
		return hit;
	if (m_min.x > other->m_max.x)
		return hit;;
	if (m_max.y < other->m_min.y)
		return hit;;
	if (m_min.y > other->m_max.y)
		return hit;
	hit.hitting = true;
	return hit;
}

Hit GameObject::BoxCircleCollision(GameObject* other)
{
	Hit hit;
	// if the circle's center point is inside of the box there is a collision
	if ((m_transform[2].x < other->m_max.x && m_transform[2].x >other->m_min.x) && (m_transform[2].y < other->m_max.y && m_transform[2].y > other->m_min.y))
	{
		hit.point = m_transform[2];
		hit.hitting = true;
		return hit;
	}
	Vector3 clampedPos = m_transform[2];

	//clamp the position
	if (m_transform[2].x > other->m_min.x)
		clampedPos.x = other->m_min.x;
	if (m_transform[2].x > other->m_max.x)
		clampedPos.x = other->m_max.x;
	if (m_transform[2].y > other->m_min.y)
		clampedPos.y = other->m_min.y;
	if (m_transform[2].y > other->m_max.y)
		clampedPos.y = other->m_max.y;

	// if the the hit.point is inside the circle
	if ((m_transform[2].x < hit.point.x && m_transform[2].x > hit.point.x) && (m_transform[2].y < hit.point.y && m_transform[2].y > hit.point.y))
	{
		hit.point = clampedPos;
		hit.hitting = true;
		return hit;
	}
	return hit;
}

Hit GameObject::CircleBoxCollision(GameObject* other)
{
	// call the BoxCircleCollision on the other GameObject
	return other->BoxCircleCollision(this);
}

Hit GameObject::CircleCircleCollision(GameObject* other)
{
	Hit hit;
	// if the distance between the center's of each circle is smaller than their half extents divided by two they are colliding
	float displacement = (m_transform[2] - other->m_transform[2]).magnitude();
	if (other->m_size.x + m_size.x > displacement)
	{
		hit.point = m_transform[2] - (other->m_transform[2]);
		hit.point = hit.point.GetNormalised();
		hit.point = hit.point * (other->m_size.x + m_size.x);
		hit.point = hit.point + (other->m_transform[2]);
		hit.hitting = true;
		return hit;
	}
	return hit;
}

GameObject::~GameObject()
{
	// delete the children of this game object when it is removed
	for (int i = 0; i < (int)m_children.size(); i++)
	{
		delete m_children[i];
	}
}
*/