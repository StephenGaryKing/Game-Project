#pragma once
#include<vector>
#include"GameState.h"

class GameStateManager
{
public:
	GameStateManager(unsigned int stateCount)
	{
		m_registeredStates.resize(stateCount);
	}
	~GameStateManager()
	{
		for (auto state : m_registeredStates) delete state;
	}

	void registerState(int id, GameState* state);
	void pushState(int id);
	void popState();

	int update(aie::Input* input, float deltaTime);

	void draw(aie::Renderer2D* renderer)
	{
		//draw from the bottom of the stack up
		//for (auto state : m_stateStack)
		//	state->onDraw(renderer);

		// just draw the top of the stack
		m_stateStack.back()->onDraw(renderer);
	}

	GameState* getTopState() const { return m_stateStack.back(); }
	int activeStateCount() const { return m_stateStack.size(); }
	GameState* getState(int id) const { return m_registeredStates[id]; }

protected:

	// handle pushing / popping while updating
	std::vector<GameState*> m_pushedStates;
	bool m_popState = false;

	std::vector<GameState*> m_stateStack;
	std::vector<GameState*> m_registeredStates;
};

