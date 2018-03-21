#include "AsteroidsManager.h"

AsteroidsManager::AsteroidsManager(SDLGame* game) : GameObject(game), 
asteroidImage_(ImageRenderer(game->getResources()->getImageTexture(Resources::ImageId::Astroid))), rotationPhysics_(2), numOfAsteroids_(0)
{
}


AsteroidsManager::~AsteroidsManager(){
}

void AsteroidsManager::handleInput(Uint32 time, const SDL_Event & event)
{
}

void AsteroidsManager::update(Uint32 time)
{
}

void AsteroidsManager::render(Uint32 time)
{
}

vector<Asteroid*>& AsteroidsManager::getAstroids()
{
	return asteroids_;
}

void AsteroidsManager::receive(Message * msg)
{
}

Asteroid * AsteroidsManager::getAsteroid()
{
	return nullptr;
}

void AsteroidsManager::initAsteroids()
{
	for (int i = 0; i < asteroids_.size(); i++)
		asteroids_[i]->setActive(false);
	for (int i = 0; i < 5; i++) {
		Uint32 x = 0, y = 0;
		asteroids_.push_back(new Asteroid(game_));
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
		double x = rand() % MAX_VEL;
		double y = rand() % MAX_VEL;
		asteroids_.back()->setVelocity(Vector2D(x, y));
	}
}
