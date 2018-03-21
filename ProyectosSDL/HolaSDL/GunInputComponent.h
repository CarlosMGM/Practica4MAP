#pragma once
#include "InputComponent.h"
#include "Observable.h"
#include "Fighter.h"

class GunInputComponent :
	public InputComponent, public Observable
{
public:
	GunInputComponent(int Maxshots, SDL_Keycode shoot);
	~GunInputComponent();
	virtual void handleInput(GameObject * o, Uint32 time, const SDL_Event & event);
private:
	bool running = false;
	int MaxShots_;
	int currentShots = 0;
	SDL_Keycode shoot_;
	Uint32 timer;
};

