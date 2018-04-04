#include "AccelerationInputComponent.h"

AccelerationInputComponent::AccelerationInputComponent(SDL_Keycode up, SDL_Keycode down, double thrust, double maxVelocity, double reduction) :
	up_(up), down_(down), thrust_(thrust), maxVelocity_(maxVelocity), reduction_(reduction){
}

AccelerationInputComponent::~AccelerationInputComponent() {
}

void AccelerationInputComponent::handleInput(GameObject* o, Uint32 time,
	const SDL_Event& event) {

	Vector2D velocity = o->getVelocity();

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == up_) {
			velocity.set(o->getVelocity() + o->getDirection()*thrust_);
			if (o->getVelocity().magnitude() > maxVelocity_) {
				velocity.set(o->getVelocity());
				velocity.normalize();
				velocity = velocity * maxVelocity_;
			}
		}
		else if (event.key.keysym.sym == down_) {
			velocity = velocity*reduction_;
		}

		o->setVelocity(velocity);
	}
}
