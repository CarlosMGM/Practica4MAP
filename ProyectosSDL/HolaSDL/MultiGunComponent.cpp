#include "MultiGunComponent.h"



MultiGunComponent::MultiGunComponent(int Maxshots, SDL_Keycode shoot): GunInputComponent(Maxshots, shoot)
{
}


MultiGunComponent::~MultiGunComponent()
{
}

void MultiGunComponent::shoot(Fighter* fighter, Vector2D position, Vector2D velocity) {
	for (int i = 0; i < 6; i++)
	{
		send(&FighterIsShooting(fighter, position, velocity * 4));
		velocity.rotate(60);
	}
}
