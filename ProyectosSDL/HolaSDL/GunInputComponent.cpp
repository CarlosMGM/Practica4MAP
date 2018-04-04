#include "GunInputComponent.h"



GunInputComponent::GunInputComponent(int MaxShots, SDL_Keycode shoot): MaxShots_(MaxShots), shoot_(shoot)
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
			v.normalize();
			send(FighterIsShooting(f, p, v * 3));
			currentShots++;
		}
	}
}
