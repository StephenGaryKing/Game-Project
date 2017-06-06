#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(Matrix3 mat, TexturePtr* f, int frameCount, GameObject* c)
{
	creator = c;
	amountOfFrames = frameCount;
	m_transform = mat;
	frames = f;
	GameObject::GameObject(mat, nullptr, { });
}

void Animation::Draw(aie::Renderer2D* renderer)
{
	// render all the frames one after another
	if (currentFrame < amountOfFrames)
	{
		//renderer->drawSpriteTransformed3x3(frames[currentFrame], m_transform);
		currentFrame++;
	}
	// once all the frames have been rendered delete this GameObject
	else
	{
		for (int i = 0; i < (int)creator->m_children.size(); i++)
		{
			if (creator->m_children[i] == this)
			{
				creator->m_children[i] = creator->m_children[(int)creator->m_children.size() - 1];
				creator->m_children.pop_back();
			}
		}
		delete this;
	}
}

Animation::~Animation()
{

}