#include "Fighter.h"



Fighter::Fighter(SDLGame* game, int id) : Container(game), id_(id)
{
	height_ = width_ = SIZE;
	active_ = false;
}


Fighter::~Fighter()
{
}

int Fighter::getId() {
	return id_;
}