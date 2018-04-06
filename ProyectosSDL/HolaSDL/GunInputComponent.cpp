#include "GunInputComponent.h"
#include <algorithm>


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
			Vector2D v = f->getVelocity();
			Vector2D p = f->getPosition();
			p = p + Vector2D(f->getWidth() / 2, f->getHeight() / 2);
			v.normalize();
			if (v.magnitude() < MIN_VEL)
				v = Vector2D(MIN_VEL / 2.0, MIN_VEL / 2.0);
			v = f->getDirection() * v.magnitude();
			v = v * 3;
			v.rotate(v.angle(f->getDirection()));
			send(&FighterIsShooting(f, p, v));
			currentShots++;
		}
	}
}
