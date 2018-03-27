#pragma once
#include "PhysicsComponent.h"
#include "GameManager.h"

class BadgeTimer : public PhysicsComponent {

public:
	BadgeTimer();
	virtual ~BadgeTimer();
	virtual void update(GameObject* o, Uint32 time);
	void start(Uint32 timeInterval);

private:
	bool on_;
	Uint32 timeOn_;
	Uint32 timeInterval_;
};
