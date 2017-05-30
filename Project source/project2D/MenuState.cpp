#include "MenuState.h"

MenuState::MenuState()
{
	m_playBtn = new Button("PLAY", Vector2(700, 200), Vector2(200, 70), Vector4(0.0f, 0.0f, 1.0f, 1.0f));
}

int MenuState::onUpdate(aie::Input* input, float deltaTime)
{
	m_playBtn->Update(input);
	if (m_playBtn->m_clicked)
	{
		return (unsigned int)eGameState::INGAME;
	}
	return -1;
}
void MenuState::onDraw(aie::Renderer2D* renderer)
{
	m_playBtn->Draw(renderer);
}
