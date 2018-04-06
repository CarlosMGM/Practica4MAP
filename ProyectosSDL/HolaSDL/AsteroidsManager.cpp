#include "AsteroidsManager.h"

AsteroidsManager::AsteroidsManager(SDLGame* game) : GameObject(game), 
asteroidImage_(ImageRenderer(game->getResources()->getImageTexture(Resources::ImageId::Astroid))), rotationPhysics_(2), numOfAsteroids_(0)
{
}


AsteroidsManager::~AsteroidsManager(){
	while (!asteroids_.empty()) {
		delete asteroids_.back();
		asteroids_.pop_back();
	}
}

void AsteroidsManager::handleInput(Uint32 time, const SDL_Event & event)
{
}

void AsteroidsManager::update(Uint32 time)
{
	for (int i = 0; i < asteroids_.size(); i++)
		if (asteroids_[i]->isActive())
			asteroids_[i]->update(time);
}

void AsteroidsManager::render(Uint32 time)
{
	for (int i = 0; i < asteroids_.size(); i++)
		if (asteroids_[i]->isActive())
			asteroids_[i]->render(time);
}

vector<Asteroid*>& AsteroidsManager::getAsteroids()
{
	return asteroids_;
}

void AsteroidsManager::receive(Message * msg)
{
	Asteroid * ast;
	switch (msg->id_)
	{
	case BULLET_ASTROID_COLLISION:
		ast = static_cast<BulletAstroidCollision*>(msg)->astroid_;
		ast->setActive(false);
		numOfAsteroids_--;
		if (ast->getGenerations() > 0) {
			int n = rand() % 3 + 1;
			for (int i = 0; i < n; i++) {
				asteroids_.push_back(new Asteroid(game_));
				asteroids_.back()->setActive(true);
				asteroids_.back()->addPhysicsComponent(&rotationPhysics_);
				asteroids_.back()->addPhysicsComponent(&circularPhysics_);
				asteroids_.back()->addRenderComponent(&asteroidImage_);
				asteroids_.back()->setGenerations(ast->getGenerations()-1);
				asteroids_.back()->setPosition(ast->getPosition());
				double ang = rand();
				Vector2D v = ast->getVelocity();
				v.rotate(ang);
				asteroids_.back()->setVelocity(v);
			}
			numOfAsteroids_ += n;
		}
		if (numOfAsteroids_ == 0)
			send(&Message(NO_MORE_ATROIDS));
		break;
	case ROUND_START:
		initAsteroids();
		break;
	}
}

Asteroid * AsteroidsManager::getAsteroid()
{
	int i = 0;
	while (i < asteroids_.size() && asteroids_[i]->isActive())
		i++;
	if (i < asteroids_.size())
		return asteroids_[i];
	else {
		asteroids_.push_back(new Asteroid(game_));
		asteroids_.back()->setActive(false);
		asteroids_.back()->addPhysicsComponent(&rotationPhysics_);
		asteroids_.back()->addPhysicsComponent(&circularPhysics_);
		asteroids_.back()->addRenderComponent(&asteroidImage_);
		asteroids_.back()->setGenerations(rand() % 2 + 1);
		return asteroids_.back();
	}
}

void AsteroidsManager::initAsteroids()
{
	for (int i = 0; i < asteroids_.size(); i++)
		asteroids_[i]->setActive(false);
	numOfAsteroids_ = rand() % 5 + 0;
	for (int i = 0; i < numOfAsteroids_; i++) {
		Uint32 x = 0, y = 0;
		asteroids_.push_back(new Asteroid(game_));
		asteroids_.back()->setActive(true);
		asteroids_.back()->addPhysicsComponent(&rotationPhysics_);
		asteroids_.back()->addPhysicsComponent(&circularPhysics_);
		asteroids_.back()->addRenderComponent(&asteroidImage_);
		asteroids_.back()->setGenerations(rand() % 2 + 1);
		int borde = rand()%4;
		if (borde == 2)
			x = game_->getWindowWidth();
		else if(borde == 3)
			y = game_->getWindowHeight();

		if (borde == 0 || borde == 2) 
			y = rand()% game_->getWindowHeight();
		else
			x = rand()%game_->getWindowWidth();
		asteroids_.back()->setPosition(Vector2D(x, y));
		double vx = rand() % MAX_VEL +0.1;
		double vy = rand() % MAX_VEL +0.1;
		asteroids_.back()->setVelocity(Vector2D(vx, vy));
	}
}
