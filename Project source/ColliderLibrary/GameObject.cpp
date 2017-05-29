#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::GameObject(Matrix3 trans, aie::Texture* tex, std::vector<Vector3> points)
{
	// set the position, rotation, and texture to the values given
	transform = trans;
	texture = tex;
	// if there is a texture provided set the half extents in x and y equal to half the width and height of the texture
	if (texture != nullptr)
		size = { (float)texture->getWidth() / 2, (float)texture->getHeight() / 2, 1 };
	// initialize the points that will be used to for collisions
	for (int i = 0; i < (int)points.size(); i++)
	{
		localPoints.push_back(points[i]);
	}
}

void GameObject::RotateGameObject(float angle)
{
	// create a matrix to rotate the game object
	Matrix3 rotationMatrix;
	currentRotation = angle;
	rotationMatrix.setRotateZ(angle);
	// apply rotation matrix
	transform = transform * rotationMatrix;
}

void GameObject::ScaleGameObject(Vector3 scale)
{
	// enlarge the GameObject by (scale.x, scale.y, scale.z)
	transform[0] = transform[0] * scale;
	transform[1] = transform[1] * scale;
}

void GameObject::TranslateGameObject(Vector3 displacement)
{
	// move the GameObject by (displacement.x, displacement.y, displacement.z) relative to its current position
	Matrix3 displacementMatrix;
	displacementMatrix[2] = displacement;
	transform = transform * displacementMatrix;
}

void GameObject::Draw(aie::Renderer2D* renderer)
{
	// if GameObject has a texture to draw
	if (texture != nullptr)
	{
		Matrix3 positionToDraw;
		GameObject* lastParent = nullptr;
		GameObject* currentParent = parent;
		// loop through the hierachy of this GameObject from parent to child to ditermine the correct order to apply transformations
		while (lastParent != parent)
		{
			while (currentParent->parent != lastParent)
			{
				currentParent = currentParent->parent;
			}
			// apply the current parent's position and rotation to the current position to draw
			positionToDraw = positionToDraw * currentParent->transform;
			lastParent = currentParent;
			currentParent = parent;
		}
		// add the local position and rotation to the current position to draw
		positionToDraw = positionToDraw * transform;
		// draw the GameObject using its texture
		renderer->drawSpriteTransformed3x3(texture, positionToDraw);

		// draw Debug lines
		if ((int)localPoints.size() == 1)
		{
			renderer->setRenderColour(1.0f, 1.0f, 1.0f, 0.5f);
			renderer->drawCircle(transform[2].x, transform[2].y, size.x);
			renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
		}
		renderer->drawLine(min.x, min.y, max.x, min.y);
		renderer->drawLine(max.x, min.y, max.x, max.y);
		renderer->drawLine(max.x, max.y, min.x, max.y);
		renderer->drawLine(min.x, max.y, min.x, min.y);
	}
	for (int i = 0; i < (int)children.size(); i++)
	{
		// draw the children of this GameObject
		children[i]->Draw(renderer);
	}
}

void GameObject::Update(float deltaTime, aie::Input* input)
{
	// update the min and max points of this GameObject
	if ((int)localPoints.size() > 0)
	{
		Matrix3 globalPosition;
		GameObject* lastParent = nullptr;
		GameObject* currentParent = parent;
		while (lastParent != parent)
			{
				while (currentParent->parent != lastParent)
				{
					currentParent = currentParent->parent;
				}
				globalPosition = globalPosition * currentParent->transform;
				lastParent = currentParent;
				currentParent = parent;
			}
		globalPosition = globalPosition * transform;
		min = globalPosition * localPoints[0];
		max = globalPosition * localPoints[0];
		for (int i = 0; i < (int)localPoints.size(); i++)
		{
			if (min.x > (globalPosition * localPoints[i]).x)
				min.x = (globalPosition * localPoints[i]).x;
			if (min.y > (globalPosition * localPoints[i]).y)
				min.y = (globalPosition * localPoints[i]).y;
			if (max.x < (globalPosition * localPoints[i]).x)
				max.x = (globalPosition * localPoints[i]).x;
			if (max.y < (globalPosition * localPoints[i]).y)
				max.y = (globalPosition * localPoints[i]).y;
		}
	}
	for (int i = 0; i < (int)children.size(); i++)
	{
		// update the min and max points of this GameObject's children
		children[i]->Update(deltaTime, input);
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

void GameObject::HandleCollision(GameObject* other, Hit hit)
{
	if (enabled)
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
	if ((int)other->localPoints.size() == 4)
	{
		//if this is a plane
		if ((int)localPoints.size() == 2)
		{
			return PlaneBox(other);
		}
		//if this is a box
		if ((int)localPoints.size() == 4)
		{
			return BoxBoxCollision(other);
		}
		//if this is a circle
		if ((int)localPoints.size() == 1)
		{
			return CircleBoxCollision(other);
		}
		return hit;
	}
	//if the other GameObject is a circle
	if ((int)other->localPoints.size() == 1)
	{
		//if this is a box
		if ((int)localPoints.size() == 4)
		{
			return CircleBoxCollision(other);
		}
		//if this is a circle
		if ((int)localPoints.size() == 1)
		{
			hit = CircleCircleCollision(other);
			if (hit.hitting)
				HandleCollision(other, hit);
			hit.hitting = false;
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
	normal = localPoints[0].GetNormalised();
	normal = Vector3(-normal.y, normal.x, 1);
	for (int i = 0; i < (int)other->localPoints.size(); i++)
	{
		float side = (other->transform * other->localPoints[i]).dot(normal);
		side += localPoints[0].z;
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
	if (max.x < other->min.x)
		return hit;
	if (min.x > other->max.x)
		return hit;;
	if (max.y < other->min.y)
		return hit;;
	if (min.y > other->max.y)
		return hit;
	hit.hitting = true;
	return hit;
}

Hit GameObject::BoxCircleCollision(GameObject* other)
{
	Hit hit;
	// if the circle's center point is inside of the box there is a collision
	if ((transform[2].x < other->max.x && transform[2].x >other->min.x) && (transform[2].y < other->max.y && transform[2].y > other->min.y))
	{
		hit.point = transform[2];
		hit.hitting = true;
		return hit;
	}
	Vector3 clampedPos = transform[2];

	//clamp the position
	if (transform[2].x > other->min.x)
		clampedPos.x = other->min.x;
	if (transform[2].x > other->max.x)
		clampedPos.x = other->max.x;
	if (transform[2].y > other->min.y)
		clampedPos.y = other->min.y;
	if (transform[2].y > other->max.y)
		clampedPos.y = other->max.y;

	// if the the hit.point is inside the circle
	if ((transform[2].x < hit.point.x && transform[2].x > hit.point.x) && (transform[2].y < hit.point.y && transform[2].y > hit.point.y))
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
	float displacement = (transform[2] - other->transform[2]).magnitude();
	if (other->size.x + size.x > displacement)
	{
		hit.point = transform[2] - (other->transform[2]);
		hit.point = hit.point.GetNormalised();
		hit.point = hit.point * (other->size.x + size.x);
		hit.point = hit.point + (other->transform[2]);
		hit.hitting = true;
		return hit;
	}
	return hit;
}

GameObject::~GameObject()
{
	// delete the children of this game object when it is removed
	for (int i = 0; i < (int)children.size(); i++)
	{
		delete children[i];
	}
}