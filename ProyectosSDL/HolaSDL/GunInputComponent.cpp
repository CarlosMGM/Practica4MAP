#include "GunInputComponent.h"
#include <algorithm>


GunInputComponent::GunInputComponent(int MaxShots, int power, SDL_Keycode shoot): MaxShots_(MaxShots), shoot_(shoot), power_(power)
{
	running = false;
}


GunInputComponent::~GunInputComponent()
{
}

void GunInputComponent::handleInput(GameObject * o, Uint32 time, const SDL_Event & event) {
	
	Fighter* f = static_cast<Fighter*>(o);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == shoot_) {
 		if (!running) {
			timer = time + 3000;
			running = true;
		}
		else if (time >= timer) {
			running = false;
			currentShots = 0;
		}
		if (currentShots < MaxShots_) {
 			Vector2D v = f->getDirection();
			Vector2D p = f->getPosition();
			p = p + Vector2D(f->getWidth() / 2, f->getHeight() / 2);
			v.normalize();
			shoot(f, p, v);
			currentShots++;
		}
	}
}

void GunInputComponent::setPower(int power) {
	power_ = power;
}

void GunInputComponent::shoot(Fighter* fighter, Vector2D position, Vector2D velocity) {
	switch (power_) {
	case 0:
		send(&FighterIsShooting(fighter, position, velocity * 4));
		break;
	case 1:
		send(&FighterIsShooting(fighter, position, velocity * 4, true));
		break;
	case 2:
		for (int i = 0; i < 6; i++)
		{
			send(&FighterIsShooting(fighter, position, velocity * 4));
			velocity.rotate(60);
		}
		break;
	default:
		break;
	}
}
