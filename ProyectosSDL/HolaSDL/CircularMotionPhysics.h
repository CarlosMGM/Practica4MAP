#pragma once
#include "BasicMotionPhysics.h"
class CircularMotionPhysics :
	public BasicMotionPhysics
{
public:
	CircularMotionPhysics();
	virtual ~CircularMotionPhysics();
	virtual void update(GameObject* o, Uint32 time);
};

