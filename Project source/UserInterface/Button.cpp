#include "Button.h"



Button::Button(char* text, Vector2 position, Vector2 size, Vector4 colour)
{
	int i = 0;
	while (text[i] != 0)
	{
		m_text[i] = text[i];
		i++;
	}
	m_text[i] = 0;

	m_colour = colour;
	m_position = position;
	m_size = size;
}

void Button::Draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(m_colour[0], m_colour[1], m_colour[2], m_colour[3]);
	renderer->drawBox(m_position.x, m_position.y, m_size.x, m_size.y);
	renderer->setRenderColour(1 - m_colour[0], 1 - m_colour[1], 1 - m_colour[2], m_colour[3]);
	renderer->drawBox(m_position.x - m_size.x/4, m_position.y, m_size.x/4, m_size.y);
	renderer->drawText(m_font, m_text, m_position.x, m_position.y);
}

void Button::Update(aie::Input* input)
{
	if (input->wasMouseButtonPressed(0))
	{
		if ((float)input->getMouseX() > m_position.x - m_size.x && (float)input->getMouseX() < m_position.x + m_size.x)
		{
			if ((float)input->getMouseY() > m_position.y - m_size.y && (float)input->getMouseY() < m_position.y + m_size.y)
			{
				m_clicked = true;
			}
		}
	}
}

Button::~Button()
{
}
