#ifndef EXAMPLEGAME_H_
#define EXAMPLEGAME_H_

#include <vector>

#include "SDLGame.h"
#include "GameObject.h"
#include "StarTrekBulletManager.h"
#include "FightersManager.h"
#include "AsteroidsManager.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "SoundManager.h"

class ExampleGame : public SDLGame {
public:
	ExampleGame();
	virtual ~ExampleGame();
	// from SDLGame
	void start();
	void stop();
private:
	
	void handleInput(Uint32 time);
	void update(Uint32 time);
	void render(Uint32 time);
	void initGame();
	void closeGame();
	StarTrekBulletManager bulletsManager_;
	FightersManager fightersManager_;
	AsteroidsManager astroidsManager_;
	CollisionManager collisionManager_;
	GameManager gameManager_;
	SoundManager soundManager_;
	const static int _WINDOW_WIDTH_ = 640;
	const static int _WINDOW_HEIGHT_ = 480;
	bool exit_;
	std::vector<GameObject*> actors_;
};
#endif /* EXAMPLEGAME_H_ */
