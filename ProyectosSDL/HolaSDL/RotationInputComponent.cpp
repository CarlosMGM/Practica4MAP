#include "RotationInputComponent.h"

RotationInputComponent::RotationInputComponent(SDL_Keycode clockwise, SDL_Keycode counterclockwise, double angle) :
	clockwise_(clockwise), counterclockwise_(counterclockwise), angle_(angle) {
}

RotationInputComponent::~RotationInputComponent() {
}

void RotationInputComponent::handleInput(GameObject* o, Uint32 time,
	const SDL_Event& event) {

	Vector2D direction = o->getDirection();

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == clockwise_) {
			direction.rotate(angle_);
		}
		else if (event.key.keysym.sym == counterclockwise_) {
			direction.rotate(-angle_);
		}
	}

	o->setDirection(direction);
}
