#pragma once
#include "GameObject.h"
class Animation :
	public GameObject
{
public:
	// constructors
	Animation();
	Animation(Matrix3 mat, TexturePtr* frames, int frameCount, GameObject* c);

	void Draw(aie::Renderer2D* renderer);
	// deconstructor
	~Animation();

private:

	GameObject* creator;
	int amountOfFrames;
	TexturePtr* frames;
	int currentFrame = 0;
};