#include "Asteroid.h"



Asteroid::Asteroid(SDLGame* game) : Container(game)
{
	width_ = SIZE;
	height_ = SIZE;
}


Asteroid::~Asteroid()
{
}

void Asteroid::setGenerations(int generations) {
	generations_ = generations;
}
int Asteroid::getGenerations() {
	return generations_;
 }