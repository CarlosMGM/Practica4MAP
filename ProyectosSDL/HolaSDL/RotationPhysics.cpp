#include "PhysicsComponent.h"
#include "RotationPhysics.h"



RotationPhysics::RotationPhysics(double angle) : angle_(angle)
{
}


RotationPhysics::~RotationPhysics()
{
}

void RotationPhysics::update(GameObject * o, Uint32 time)
{
	Vector2D v = o->getDirection();
	v.rotate(angle_);
	o->setDirection(v);
}
