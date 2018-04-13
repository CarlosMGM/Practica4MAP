#include "Bullet.h"



Bullet::Bullet(SDLGame* game, bool super) : Container(game), super_(super){
	width_ = height_ = 4;
}


Bullet::~Bullet(){

}

void Bullet::setFighterId(int id) {
	fighterId_ = id;
}

int Bullet::getFighterId() {
	return fighterId_;
}

void Bullet::setSuper(bool super) {
	super_ = super;
}

bool Bullet::isSuper()
{
	return super_;
}
