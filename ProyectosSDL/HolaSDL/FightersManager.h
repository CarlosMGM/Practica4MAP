#pragma once
#include "GameObject.h"
#include "Observer.h"
#include "CircularMotionPhysics.h"
#include "AccelerationInputComponent.h"
#include "ImageRenderer.h"
#include "RotationInputComponent.h"
#include "GunInputComponent.h"
#include "BadgeRenderer.h"

class FightersManager : public GameObject, public Observer {
public:
	FightersManager(SDLGame* game, Observer* bulletsManager);
	virtual ~FightersManager();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	Fighter* getFighter();
	virtual void receive(Message* msg);
private:
	bool badgeState = false;
	Fighter fighter_;
	CircularMotionPhysics circulrMotoionComp_;
	AccelerationInputComponent accelerationComp_;
	ImageRenderer renderComp_ ;
	RotationInputComponent rotationComp_;
	GunInputComponent gunComp1_;
	GunInputComponent gunComp2_;
	BadgeRenderer badgeRenderer_;
};