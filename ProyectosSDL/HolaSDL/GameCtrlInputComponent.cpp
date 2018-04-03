#include "GameCtrlInputComponent.h"
#include "GameManager.h"

GameCtrlInputComponent::GameCtrlInputComponent(SDL_Keycode start) : start_(start)
{
}

GameCtrlInputComponent::~GameCtrlInputComponent()
{
}

void GameCtrlInputComponent::handleInput(GameObject * o, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == start_) {
			static_cast<GameManager*>(o)->send(Message(ROUND_START));
			static_cast<GameManager*>(o)->setRunning(true);
		}
	}
}
