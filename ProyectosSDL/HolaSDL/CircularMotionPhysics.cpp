#include "CircularMotionPhysics.h"



CircularMotionPhysics::CircularMotionPhysics()
{
}


CircularMotionPhysics::~CircularMotionPhysics()
{
}

void CircularMotionPhysics::update(GameObject * o, Uint32 time)
{
	BasicMotionPhysics::update(o, time);
	Vector2D pos = o->getPosition();
	SDLGame * g = o->getGame();
	if (pos.getX() < -o->getWidth())
		pos.setX(g->getWindowWidth());
	else if (pos.getX() > g->getWindowWidth())
		pos.setX(-o->getWidth());


	if (pos.getY() < -o->getHeight())
		pos.setY(g->getWindowHeight());
	else if (pos.getY() > g->getWindowHeight())
		pos.setY(-o->getHeight());

	o->setPosition(pos);
}
