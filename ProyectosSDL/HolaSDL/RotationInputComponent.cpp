#include "RotationInputComponent.h"




RotationInputComponent::RotationInputComponent(double rotation, SDL_Keycode clockWise, 
	SDL_Keycode counterClockWise) : rotation_(rotation), clockWise_(clockWise), 
	counterClockWise_(counterClockWise)
{
}

RotationInputComponent::~RotationInputComponent()
{
}

void RotationInputComponent::handleInput(GameObject * o, Uint32 time, const SDL_Event & event)
{
	Vector2D dir = o->getDirection();

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == clockWise_) {
			dir.rotate(rotation_);
		}
		else if (event.key.keysym.sym == counterClockWise_) {
			dir.rotate(-rotation_);
		}

		o->setDirection(dir);
	}
}
