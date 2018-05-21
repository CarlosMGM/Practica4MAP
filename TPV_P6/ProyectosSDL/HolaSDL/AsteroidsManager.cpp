#include "AsteroidsManager.h"

#include "Collisions.h"

AsteroidsManager::AsteroidsManager(SDLGame* game) :
		GameObject(game), asteroidImage_(ImageRenderer(game->getResources()->getImageTexture(Resources::ImageId::Astroid))), 
	rotationPhysics_(2){
}

AsteroidsManager::~AsteroidsManager() {
	for each (Asteroid* var in asteroids_)
		delete var;
}

vector<Asteroid*>& AsteroidsManager::getAsteroids() {
	return asteroids_;
}

void AsteroidsManager::handleInput(Uint32 time, const SDL_Event& event) {
}

void AsteroidsManager::update(Uint32 time) {
	if (running && (time - lastTimeNewAsteroid) > CREATION_INTERVAL) {
		addAsteroid();
		lastTimeNewAsteroid = time;
	}
	for (Asteroid* a : asteroids_)
		if (a->isActive()) {
			a->update(time);
		}
}

void AsteroidsManager::render(Uint32 time) {
	for (Asteroid* a : asteroids_)
		if (a->isActive()) {
			a->render(time);
		}
}

void AsteroidsManager::receive(Message* msg) {
	switch (msg->mType_) {
	case GAME_START:
		if (game_->isMasterClient()) {
			running = true;
			lastTimeNewAsteroid = 0;
		}
		break;
	case ASTEROID_STATE:
		updateAsteroidState(static_cast<AsteroidStateMsg*>(msg));
		break;

	case GAME_OVER:
		running = false;
		for (Asteroid * a : asteroids_)
			a->setActive(false);
		break;
	}
}

void AsteroidsManager::addAsteroid()
{
	Asteroid*ast = getAsteroid();
	
	Vector2D vel((1 - 2 * (rand() % 2))*((rand() % 10) + 1), ((rand() % 10) + 1));
	vel.normalize();
	vel = vel * 0.5;
	Vector2D pos(rand() % getGame()->getWindowWidth(), rand() % 30);
	Vector2D dir(0, -1);
	int width = (rand() % 10) + 20;
	int height = (rand() % 10) + 20;

	ast->setVelocity(vel);
	ast->setPosition(pos);
	ast->setDirection(dir);
	ast->setWidth(width);
	ast->setHeight(height);

	sendAsteroidState(ast);


}

Asteroid * AsteroidsManager::newAsteroid()
{
	asteroids_.push_back(new Asteroid(game_));
	asteroids_.back()->setActive(true);
	asteroids_.back()->setAsteroidId(asteroids_.size() - 1);
	asteroids_.back()->addPhysicsComponent(&rotationPhysics_);
	asteroids_.back()->addPhysicsComponent(&inBoundsPhysics_);
	asteroids_.back()->addRenderComponent(&asteroidImage_);
	return asteroids_.back();
}

Asteroid * AsteroidsManager::getAsteroid()
{
	int i = 0;
	while (i < asteroids_.size() && asteroids_[i]->isActive())
		i++;
	if (i < asteroids_.size()) {
		asteroids_[i]->setActive(true);
		return asteroids_[i];

	}
	else {
		return newAsteroid();
	}
}

void AsteroidsManager::sendAsteroidState(Asteroid * a) {
	AsteroidStateMsg msg = { //
		a->getAsteroidId(), //
		a->getPosition(), //
		a->getDirection(), //
		a->getVelocity(), //
		a->getWidth(), //
		a->getHeight() //
	};
	send(&msg);
}

void AsteroidsManager::updateAsteroidState(AsteroidStateMsg* msg) {
	Asteroid* a;
	if (asteroids_.size() == msg->asteroidId_) {
		a = newAsteroid();
	}
	else
		a = asteroids_[msg->asteroidId_];

	a->setActive(true);
	a->setWidth(msg->width_);
	a->setHeight(msg->height_);
	a->setPosition(msg->pos_);
	a->setDirection(msg->dir_);
	a->setVelocity(msg->vel_);
}
