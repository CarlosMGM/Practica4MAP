#pragma once
#include "Asteroid.h"
#include "GameObject.h"
#include "Observer.h"
#include "Observable.h"
#include "ImageRenderer.h"
#include "CircularMotionPhysics.h"
#include "RotationPhysics.h"

#define MAX_VEL 2

class AsteroidsManager : public GameObject, public Observer, public Observable {
public:
	AsteroidsManager(SDLGame* game);
	virtual ~AsteroidsManager();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual vector<Asteroid*>& getAsteroids();
	virtual void receive(Message* msg);
private:
	Asteroid* getAsteroid();
	void initAsteroids();

	vector<Asteroid*> asteroids_;
	ImageRenderer asteroidImage_ ;
	CircularMotionPhysics circularPhysics_;
	RotationPhysics rotationPhysics_;
	int numOfAsteroids_ = 0;
};
