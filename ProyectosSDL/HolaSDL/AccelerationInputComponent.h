#pragma once
#include "InputComponent.h"
class AccelerationInputComponent :
	public InputComponent
{
public:
	AccelerationInputComponent(double thrust, double factor, double limit, double epsilon,
		SDL_Keycode accelerate, SDL_Keycode decelerate);
	~AccelerationInputComponent();
	void handleInput(GameObject * o, Uint32 time, const SDL_Event & event);

private:
	double thrust_;
	double limit_;
	double factor_;
	double epsilon_;
	SDL_Keycode accelerate_;
	SDL_Keycode decelerate_;
};

