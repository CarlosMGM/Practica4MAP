#pragma once
#include "Container.h"
class Bullet : public Container {
public:
	Bullet(SDLGame* game, bool super = false);
	virtual ~Bullet();
	void setFighterId(int id);
	int getFighterId();
	void setSuper(bool super);
	bool isSuper();
private:
	int fighterId_;
	bool super_;
};
