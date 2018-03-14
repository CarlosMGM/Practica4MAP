#pragma once
#include "GameObject.h"
#include "BulletsManager.h"
class StarWarsBulletsManager :
	public GameObject, public BulletsManager
{
private:
	std::vector<GameObject*> * bullets = nullptr;
public:
	StarWarsBulletsManager(SDLGame*g);
	~StarWarsBulletsManager();
	void shoot(GameObject*o, Vector2D p, Vector2D v);
	void update(Uint32 time);
	void render(Uint32 time);


	void handleInput(Uint32 time, const SDL_Event& event);
};

