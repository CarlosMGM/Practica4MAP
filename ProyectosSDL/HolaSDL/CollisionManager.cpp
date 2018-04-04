#include "CollisionManager.h"
#include "Collisions.h"

CollisionManager::CollisionManager(SDLGame * game, BulletsManager * bulletsManager, AsteroidsManager * asteroidManager, FightersManager * fightersManager)
		: GameObject(game), bulletsManager_(bulletsManager), asteroidsManager_(asteroidManager), fightersManager_(fightersManager)
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::handleInput(Uint32 time, const SDL_Event & event)
{
}

void CollisionManager::update(Uint32 time)
{
	vector<Bullet*> bullets = bulletsManager_->getBullets();
	vector<Asteroid*> asteroids = asteroidsManager_->getAsteroids();
	Fighter* fighter = fightersManager_->getFighter();

	// fighter with asteroids
	for (int i = 0; i < asteroids.size(); i++)
		if (asteroids[i]->isActive() && fighter->isActive() && Collisions::collidesWithRotation(fighter, asteroids[i]))
			send(AstroidFighterCollision(asteroids[i], fighter));

	// bullets with asteroids
	for (int i = 0; i < bullets.size(); i++)
		for (int j = 0; j < asteroids.size(); j++)
			if (bullets[i]->isActive() && asteroids[j]->isActive() && Collisions::collidesWithRotation(bullets[i], asteroids[j]))
				send(BulletAstroidCollision(bullets[i], asteroids[j]));
}

void CollisionManager::render(Uint32 time)
{
}
