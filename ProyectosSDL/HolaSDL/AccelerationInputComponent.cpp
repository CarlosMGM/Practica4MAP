#include "AccelerationInputComponent.h"


AccelerationInputComponent::AccelerationInputComponent(double thrust, double factor, double limit, 
	double epsilon,	SDL_Keycode accelerate, SDL_Keycode decelerate) : thrust_(thrust), factor_(factor), 
	limit_(limit), epsilon_(epsilon), accelerate_(accelerate), decelerate_(decelerate)
{
}

AccelerationInputComponent::~AccelerationInputComponent()
{
}

void AccelerationInputComponent::handleInput(GameObject * o, Uint32 time, const SDL_Event & event)
{
	Vector2D vel = o->getVelocity();
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == accelerate_) {
			vel = vel + o->getDirection() * thrust_;;
			if (vel.magnitude() > limit_) {
				vel.normalize();
				vel = vel * limit_;
			}
		}
		else if (event.key.keysym.sym == decelerate_) {
			vel = vel - vel * factor_;
			if (vel.magnitude() <= epsilon_)
				vel.set(Vector2D(0, 0));
		}

		o->setVelocity(vel);
	}
}