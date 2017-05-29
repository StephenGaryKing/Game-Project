#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(Matrix3 mat, aie::Texture** f, int frameCount, GameObject* c)
{
	creator = c;
	amountOfFrames = frameCount;
	transform = mat;
	frames = f;
	GameObject::GameObject(mat, nullptr, { });
}

void Animation::Draw(aie::Renderer2D* renderer)
{
	// render all the frames one after another
	if (currentFrame < amountOfFrames)
	{
		renderer->drawSpriteTransformed3x3(frames[currentFrame], transform);
		currentFrame++;
	}
	// once all the frames have been rendered delete this GameObject
	else
	{
		for (int i = 0; i < (int)creator->children.size(); i++)
		{
			if (creator->children[i] == this)
			{
				creator->children[i] = creator->children[(int)creator->children.size() - 1];
				creator->children.pop_back();
			}
		}
		delete this;
	}
}

Animation::~Animation()
{

}