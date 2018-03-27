#pragma once
#include "Container.h"
#include "Observer.h"
#include "Observable.h"
#include "BadgeTimer.h"

class GameManager : public Container, public Observer, public Observable {

public:
	GameManager(SDLGame* game);
	virtual ~GameManager();
	bool isGameOver() const;
	int getLives() const;
	bool isRunning() const;
	void setRunning(bool running);
	int getScore() const;
	void setBadge(bool b);
	void receive(Message* msg);

private:
	int score = 0;
	int badgeCounter = 0;
	int lives = 3;
	/*ScoreRenderer scoreRenderer_;
	LiveRenderer livesRenderer_;
	GameCtrlInputComponent gameCtrl_;
	GameMsgRenderer gameMsg_;*/
	BadgeTimer badgeTimer_;
};
