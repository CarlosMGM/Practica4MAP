#include "GameManager.h"



GameManager::GameManager(SDLGame* game): Container(game), Observer(), Observable()
{
}


GameManager::~GameManager()
{
}

void GameManager::setBadge(bool b) {
	if (b)
		send(Message(BADGE_ON));
	else
		send(Message(BADGE_OFF));
}

bool GameManager::isGameOver() const {

}

int GameManager::getLives() const {

}

bool GameManager::isRunning() const {

}

void GameManager::setRunning(bool running) {

}

int GameManager::getScore() const {

}

void GameManager::receive(Message* msg) {
	
	switch (msg->id_) {
	case ASTROID_FIGHTER_COLLISION: {
		badgeCounter = 0;
		lives--;
		setBadge(false);
		send(Message(ROUND_OVER));
		if (lives == 0) {
			send(Message(GAME_OVER));
			}
		}
				break;
		case BULLET_ASTROID_COLLISION: {
			score++;
			badgeCounter++;
			if (badgeCounter == 9) {
				setBadge(true);
				badgeTimer_.start(10000);
			}
		}	
				break;
		case NO_MORE_ATROIDS: {
			setBadge(false);
			send(Message(ROUND_OVER));
			send(Message(GAME_OVER));
		}
				break;
			
	}
}