#include "BadgeTimer.h"



BadgeTimer::BadgeTimer()
{
}


BadgeTimer::~BadgeTimer()
{
}

void BadgeTimer::start(Uint32 timeInterval) {
	on_ = true;
	timeOn_ = SDL_GetTicks();
	timeInterval_ = timeInterval;
}

void BadgeTimer::update(GameObject* o, Uint32 time) {
	GameManager* GM = static_cast<GameManager*>(o);
	if (on_ && time > timeOn_ + timeInterval_)
		GM->setBadge(false);
		
}