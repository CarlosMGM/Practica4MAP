#include "CircularMotionPhysics.h"

CircularMotionPhysics::CircularMotionPhysics() {

}

CircularMotionPhysics::~CircularMotionPhysics() {
}

void CircularMotionPhysics::update(GameObject* o, Uint32 time) {
	o->setPosition(o->getPosition() + o->getVelocity());
	if (o->getPosition().getX() > o->getGame()->getWindowWidth() + 10.0)
		o->setPosition(Vector2D(0.0, o->getPosition().getY()));
	else if (o->getPosition().getX() < -10.0)
		o->setPosition(Vector2D(o->getGame()->getWindowWidth() + -9.0, o->getPosition().getY()));
	if (o->getPosition().getY() > o->getGame()->getWindowHeight() + 10.0)
		o->setPosition(Vector2D(o->getPosition().getX(), 0.0));
	else if (o->getPosition().getY() < -10.0)
		o->setPosition(Vector2D(o->getPosition().getX(), o->getGame()->getWindowHeight() + -9.0));
}
