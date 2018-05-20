#pragma once
#include "BasicMotionPhysics.h"

class InBoundsMotionPhysics :
	public BasicMotionPhysics
{
public:
	InBoundsMotionPhysics();
	virtual ~InBoundsMotionPhysics();
	virtual void update(GameObject* o, Uint32 time);
};

