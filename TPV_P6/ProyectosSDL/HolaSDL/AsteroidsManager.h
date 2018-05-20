#pragma once

#include "GameObject.h"
#include "ImageRenderer.h"
#include "InBoundsMotionPhysics.h"
#include "RotationPhysics.h"
#include "Observer.h"
#include "SkeletonRenderer.h"
#include "Observable.h"
#include "Asteroid.h"

#define CREATION_INTERVAL 10000

/*
 *
 */
class AsteroidsManager: public GameObject, public Observer, public Observable {

public:
	AsteroidsManager(SDLGame* game);
	virtual ~AsteroidsManager();
	virtual vector<Asteroid*>& getAsteroids();

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual void receive(Message* msg);

private:

	bool running = false;
	ImageRenderer asteroidImage_;
	RotationPhysics rotationPhysics_;
	InBoundsMotionPhysics inBoundsPhysics_;
	Uint32 lastTimeNewAsteroid;
	vector<Asteroid*> asteroids_;


	void addAsteroid();
	Asteroid * newAsteroid();
	Asteroid * getAsteroid();
	void sendAsteroidState(Asteroid * ast);
	void updateAsteroidState(AsteroidStateMsg * msg);
};

