#ifndef ACCELERATIONINPUTCOMPONENT_H_
#define ACCELERATIONINPUTCOMPONENT_H_

#include "InputComponent.h"

/*
*
*/
class AccelerationInputComponent : public InputComponent {
public:
	AccelerationInputComponent(SDL_Keycode up, SDL_Keycode down, double thrust, double maxVelocity, double reduction);
	virtual ~AccelerationInputComponent();
	virtual void handleInput(GameObject* o, Uint32 time,
		const SDL_Event& event);
private:
	SDL_Keycode up_;
	SDL_Keycode down_;
	double thrust_;
	double maxVelocity_;
	double reduction_;
};

#endif /* ACCELERATIONINPUTCOMPONENT_H_ */
