#pragma once
#include "InputComponent.h"
#include "Observable.h"
#include "Fighter.h"

#define MIN_VEL 2

class GunInputComponent :
	public InputComponent, public Observable
{
public:
	GunInputComponent(int Maxshots, int power, SDL_Keycode shoot);
	~GunInputComponent();
	virtual void handleInput(GameObject * o, Uint32 time, const SDL_Event & event);
	virtual void setPower(int power);
protected:
	virtual void shoot(Fighter* fighter, Vector2D position, Vector2D velocity);
	bool running = false;
	int power_;
	int MaxShots_;
	int currentShots = 0;
	SDL_Keycode shoot_;
	Uint32 timer;
};

