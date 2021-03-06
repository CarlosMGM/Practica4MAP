#pragma once
#include "GameObject.h"
#include "Observable.h"
#include "BulletsManager.h"
#include "AsteroidsManager.h"
#include "FightersManager.h"

class CollisionManager :
	public GameObject, public Observable
{
public:
	CollisionManager(SDLGame* game,	BulletsManager* bulletsManager,	AsteroidsManager* asteroidManager, FightersManager* fightersManager);
	virtual ~CollisionManager();
	virtual void handleInput(Uint32 time, const SDL_Event & event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	BulletsManager* bulletsManager_;
	AsteroidsManager* asteroidsManager_;
	FightersManager* fightersManager_;

};

