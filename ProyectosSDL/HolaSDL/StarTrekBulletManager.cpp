#include "StarTrekBulletManager.h"



StarTrekBulletManager::StarTrekBulletManager(SDLGame* game) : GameObject(game)
{
	bulletRenderer_ = FillRectRenderer();
	bulletPhysics_ = BasicMotionPhysics();
}


StarTrekBulletManager::~StarTrekBulletManager()
{
}

void StarTrekBulletManager::update(Uint32 time){
	for each (Bullet* var in bullets_)
	{
		var->update(time);
		Vector2D pos = var->getPosition();

		if (pos.getX > game_->getWindowWidth() || pos.getX < 0
			|| pos.getY > game_->getWindowHeight() || pos.getY < 0)
			var->setActive(false);
	}
}

void StarTrekBulletManager::render(Uint32 time) {
	for each (Bullet* var in bullets_)
	{
		var->render(time);
	}
}

void StarTrekBulletManager::handleInput(Uint32 time, const SDL_Event& event){

}

std::vector<Bullet*>& StarTrekBulletManager::getBullets() {
	return bullets_;
}

Bullet* StarTrekBulletManager::getBullet() {
	int i = 0;
	while (i < bullets_.size())
	{
		if (!bullets_[i]->isActive())
			return bullets_[i];
	}

	Bullet* bullet = new Bullet(game_);
	bullet->addPhysicsComponent(& bulletPhysics_);
	bullet->addRenderComponent(& bulletRenderer_);
	return bullet;
}

void StarTrekBulletManager::shoot(Fighter* owner, Vector2D position, Vector2D velocity){
	Bullet* bullet = getBullet();
	bullet->setPosition(position);
	bullet->setVelocity(velocity);
}

void StarTrekBulletManager::receive(Message* msg) {
	switch (msg->id_) {
	case ROUND_START:
		for each (Bullet* var in bullets_)
		{
			var->setActive(false);
		}
			break;
	case ROUND_OVER:
		for each (Bullet* var in bullets_)
		{
			var->setActive(false);
		}
			break;
	case BULLET_ASTROID_COLLISION:
		BulletAstroidCollision* m = static_cast<BulletAstroidCollision*>(msg);
		m->bullet_->setActive(false);
			break;
	case BULLET_FIGHTER_COLLISION:
		BulletFighterCollision* m = static_cast<BulletFighterCollision*>(msg);
		m->bullet_->setActive(false);
			break;
	case FIGHTER_SHOOT:
		FighterIsShooting* m = static_cast<FighterIsShooting*>(msg);
		//shoot(m->fighter_, m->bulletPosition_, m->bulletVelocity_);
			break;
		
	}
}