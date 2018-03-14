#pragma once
#include "InputComponent.h"
class RotationInputComponent :
	public InputComponent
{
public:
	RotationInputComponent(double rotation, SDL_Keycode clockWise, SDL_Keycode counterClockWise);
	~RotationInputComponent();
	virtual void handleInput(GameObject* o, Uint32 time, const SDL_Event& event);
private:
	double rotation_;
	SDL_Keycode clockWise_;
	SDL_Keycode counterClockWise_;
};

