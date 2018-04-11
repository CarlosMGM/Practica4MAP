#pragma once
#include "GunInputComponent.h"
class MultiGunComponent :
	public GunInputComponent
{
public:
	MultiGunComponent(int Maxshots, SDL_Keycode shoot);
	~MultiGunComponent();
protected:
	virtual void shoot(Fighter* fighter, Vector2D position, Vector2D velocity);
};

