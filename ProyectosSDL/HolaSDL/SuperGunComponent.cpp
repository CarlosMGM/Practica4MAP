#include "SuperGunComponent.h"



SuperGunComponent::SuperGunComponent(int Maxshots, SDL_Keycode shoot): GunInputComponent(Maxshots, shoot)
{
}


SuperGunComponent::~SuperGunComponent()
{
}

void SuperGunComponent::shoot(Fighter * fighter, Vector2D position, Vector2D velocity)
{
	send(&FighterIsShooting(fighter, position, velocity * 4, true));
}
