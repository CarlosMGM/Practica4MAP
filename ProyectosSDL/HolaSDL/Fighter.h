#pragma once
#include "Container.h"
#define SIZE 40

class Fighter : public Container {
public:
	Fighter(SDLGame* game, int id);
	virtual ~Fighter();
	int getId();
private:
	int id_;
};
