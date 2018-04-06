#pragma once
#include "Container.h"
#include "Observer.h"
#include "Observable.h"
#include "ScoreRenderer.h"
#include "LivesRenderer.h"
#include "GameCtrlInputComponent.h"
#include "GameMsgRenderer.h"
#include "BadgeTimer.h"

class GameManager : public Container, public Observer, public Observable {

public:
	GameManager(SDLGame* game);
	virtual ~GameManager();

	void virtual update(Uint32 time);
	bool isGameOver() const;
	int getLives() const;
	bool isRunning() const;
	void setRunning(bool running);
	int getScore() const;
	void setBadge(bool b);
	void receive(Message* msg);

private:
	bool running_ = false;
	int score_ = 0;
	int badgeCounter_ = 0;
	int lives_ = 3;
	
	ScoreRenderer scoreRenderer_;
	LivesRenderer livesRenderer_;
	GameCtrlInputComponent gameCtrl_;
	GameMsgRenderer gameMsg_;
	BadgeTimer badgeTimer_;
};

