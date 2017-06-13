#pragma once
#include <vector>
#include "GameState.h"

enum class eGameState
{
	SPLASH,
	MENU,
	INGAME,
	PAUSE,
	STATE_COUNT
};


class GameStateManager
{
public:
	GameStateManager(unsigned int stateCount, aie::Input* input, aie::Renderer2D* renderer)
	{
		m_registeredStates.resize(stateCount);
		m_input = input;
		m_renderer = renderer;
	}
	~GameStateManager()
	{
		for (auto state : m_registeredStates)
			delete state;
	}

	void registerState(int id, GameState* state) { state->m_input = m_input; state->m_renderer = m_renderer; m_registeredStates[id] = state; }
	void pushState(int id) { m_pushedStates.push_back(m_registeredStates[id]); }
	void popState() { m_popState = true; }

	void update(float deltaTime)
	{
		while (m_popState)
		{
			m_popState = false;

			// deactivate previous top
			m_stateStack.back()->exit();
			auto temp = m_stateStack.back();
			m_stateStack.pop_back();
			temp->onPopped();

			//activate the one under the previous top if it exists
			if (m_stateStack.empty() == false)
				m_stateStack.back()->enter();
		}

		for (auto pushedState : m_pushedStates)
		{
			//deactivate previous top
			if (m_stateStack.empty() == false)
				m_stateStack.back()->exit();

			//activate new top
			pushedState->onPushed();
			m_stateStack.push_back(pushedState);
			m_stateStack.back()->enter();
		}
		m_pushedStates.clear();

		for (auto state : m_stateStack)
			state->onUpdate(deltaTime);
	}

	void draw()
	{
		// draw from the bottom of the stack up
		for (auto state : m_stateStack)
			state->onDraw();
	}

	int activeStateCount() const { return m_stateStack.size(); }
	GameState* getTopState() const { return m_stateStack.back(); }
	GameState* getState(int id) const { return m_registeredStates[id]; }

private:

	std::vector<GameState*> m_pushedStates;
	bool m_popState = false;

	std::vector<GameState*> m_stateStack;
	std::vector<GameState*> m_registeredStates;

	aie::Renderer2D*			m_renderer = nullptr;
	aie::Input*					m_input = nullptr;
};

