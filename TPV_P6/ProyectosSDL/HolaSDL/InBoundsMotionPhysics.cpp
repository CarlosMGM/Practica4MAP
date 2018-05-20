#include "InBoundsMotionPhysics.h"



InBoundsMotionPhysics::InBoundsMotionPhysics()
{
}


InBoundsMotionPhysics::~InBoundsMotionPhysics()
{
}

void InBoundsMotionPhysics::update(GameObject* o, Uint32 time) {
	BasicMotionPhysics::update(o, time);
	if (o->getPosition().getX() + o->getWidth() < 0 ||
		o->getPosition().getX() >= o->getGame()->getWindowWidth() ||
		o->getPosition().getY() + o->getHeight() < 0 ||
		o->getPosition().getY() >= o->getGame()->getWindowHeight())
		o->setActive(false);
}