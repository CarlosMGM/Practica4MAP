#include "Bullet.h"



Bullet::Bullet(SDLGame* game) : Container(game){
	width_ = height_ = 10;
}


Bullet::~Bullet(){

}

void Bullet::setFighterId(int id) {
	fighterId_ = id;
}

int Bullet::getFighterId() {
	return fighterId_;
}