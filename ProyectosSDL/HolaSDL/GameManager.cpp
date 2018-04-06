#include "GameManager.h"



GameManager::GameManager(SDLGame* game): Container(game), Observer(), Observable(), livesRenderer_(LivesRenderer(game)), gameCtrl_(GameCtrlInputComponent(SDLK_RETURN))
{

	this->addRenderComponent(&scoreRenderer_);
	this->addRenderComponent(&livesRenderer_);
	this->addInputComponent(&gameCtrl_);
	this->addRenderComponent(&gameMsg_);
}


GameManager::~GameManager()
{
}

void GameManager::update(Uint32 time) {
	badgeTimer_.update(this, time);
}

void GameManager::setBadge(bool b) {
	if (b)
		send(&Message(BADGE_ON));
	else
		send(&Message(BADGE_OFF));
}

bool GameManager::isGameOver() const {
	return lives_ < 0;
}

int GameManager::getLives() const {
	return lives_;
}

bool GameManager::isRunning() const {
	return running_;
}

void GameManager::setRunning(bool running) {
	running_ = running;
	if (running) {
		this->addRenderComponent(&gameMsg_);
		lives_ = 3;
	}
	else
		this->delRenderComponent(&gameMsg_);
}

int GameManager::getScore() const {
	return score_;
}

void GameManager::receive(Message* msg) {
	
	switch (msg->id_) {
	case ASTROID_FIGHTER_COLLISION: {
		badgeCounter_ = 0;
		lives_--;
		setBadge(false);
		send(&Message(ROUND_OVER));
		if (isGameOver()) {
			send(&Message(GAME_OVER));
			setRunning(false);
			}
		else {
			send(&Message(ROUND_START));
		}
		}
				break;
		case BULLET_ASTROID_COLLISION: {
			score_++;
			badgeCounter_++;
			if (badgeCounter_ == 9) {
				setBadge(true);
				badgeTimer_.start(10000);
			}
		}	
				break;
		case NO_MORE_ATROIDS: {
			setBadge(false);
			send(&Message(ROUND_OVER));
			send(&Message(GAME_OVER));
		}
				break;
			
	}
}