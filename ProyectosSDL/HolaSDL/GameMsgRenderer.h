#pragma once
#include "RenderComponent.h"
#include <string>

class GameMsgRenderer :
	public RenderComponent
{
public:
	GameMsgRenderer();
	~GameMsgRenderer();
	void render(GameObject* o, Uint32 time);
};

