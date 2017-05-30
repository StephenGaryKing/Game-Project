#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "Font.h"
#include "Vector2.h"
#include "Vector4.h"
class Button
{
public:
	Button() {}
	Button(char* text, Vector2 position, Vector2 size, Vector4 colour);

	void Draw(aie::Renderer2D* renderer);
	void Update(aie::Input* input);

	~Button();

	bool				m_clicked = false;

private:
	Vector4				m_colour;
	Vector2				m_position;
	Vector2				m_size;
	char				m_text[10];
	aie::Font*			m_font = new aie::Font("./font/consolas.ttf", 32);
};

