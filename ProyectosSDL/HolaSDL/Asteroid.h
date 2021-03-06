#pragma once
#include "Container.h"
#define SIZE 25

class Asteroid : public Container {
public:
	Asteroid(SDLGame* game);
	virtual ~Asteroid();
	virtual void setGenerations(int generations);
	virtual int getGenerations();
private:
	int generations_;
};
