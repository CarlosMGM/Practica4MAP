#pragma once
#include "InputComponent.h"

class GameCtrlInputComponent :
	public InputComponent
{
private:
	SDL_Keycode start_;
public:
	GameCtrlInputComponent(SDL_Keycode start);
	~GameCtrlInputComponent();

	virtual void handleInput(GameObject* o, Uint32 time,
		const SDL_Event& event);
};


