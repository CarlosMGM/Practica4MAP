#pragma once
#include "GunInputComponent.h"
class SuperGunComponent :
	public GunInputComponent
{
public:
	SuperGunComponent(int Maxshots, SDL_Keycode shoot);
	~SuperGunComponent();
protected:
	virtual void shoot(Fighter* fighter, Vector2D position, Vector2D velocity);
};

