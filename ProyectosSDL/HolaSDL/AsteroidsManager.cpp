#include "AsteroidsManager.h"
#include <algorithm>

AsteroidsManager::AsteroidsManager(SDLGame* game) : GameObject(game), 
asteroidImage_(ImageRenderer(game->getResources()->getImageTexture(Resources::ImageId::Astroid))), rotationPhysics_(2), numOfAsteroids_(0)
{
}


AsteroidsManager::~AsteroidsManager(){
	for each (Asteroid* var in asteroids_)
		delete var;
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
				Asteroid* aux = getAsteroid();
				aux->setGenerations(ast->getGenerations()-1);
				aux->setPosition(ast->getPosition());
				double ang = rand();
				Vector2D v = ast->getVelocity();
				v.rotate(ang);
				aux->setVelocity(v);
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
	if (i < asteroids_.size()) {
		asteroids_[i]->setActive(true);
		return asteroids_[i];

	}
	else {
		asteroids_.push_back(new Asteroid(game_));
		asteroids_.back()->setActive(true);
		asteroids_.back()->addPhysicsComponent(&rotationPhysics_);
		asteroids_.back()->addPhysicsComponent(&circularPhysics_);
		asteroids_.back()->addRenderComponent(&asteroidImage_);
		return asteroids_.back();
	}
}

void AsteroidsManager::initAsteroids()
{
	for (int i = 0; i < asteroids_.size(); i++)
		asteroids_[i]->setActive(false);
	numOfAsteroids_ = rand() % 5 + 5;
	for (int i = 0; i < numOfAsteroids_; i++) {
		Uint32 x = 0, y = 0;
		Asteroid*ast = getAsteroid();
		ast->setGenerations(rand() % 2 + 1);
		int borde = rand()%4;
		if (borde == 2)
			x = game_->getWindowWidth();
		else if(borde == 3)
			y = game_->getWindowHeight();

		if (borde == 0 || borde == 2) 
			y = rand()% game_->getWindowHeight();
		else
			x = rand()%game_->getWindowWidth();
		ast->setPosition(Vector2D(x, y));
		double vx = max(static_cast<double>(rand() % MAX_VEL), 0.5);
		double vy = max(static_cast<double>(rand() % MAX_VEL), 0.5);
		ast->setVelocity(Vector2D(vx, vy));
	}
}
