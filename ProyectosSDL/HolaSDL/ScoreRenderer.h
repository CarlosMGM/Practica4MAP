#pragma once
#include "RenderComponent.h"

class ScoreRenderer :
	public RenderComponent
{
public:
	ScoreRenderer();
	~ScoreRenderer();
	void render(GameObject* o, Uint32 time);
};

