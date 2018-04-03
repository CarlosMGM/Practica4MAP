#pragma once
#include "ImageRenderer.h"
#define SIZE 80;

class BadgeRenderer :
	public ImageRenderer
{
public:
	BadgeRenderer(SDLGame * game, Uint32 row, Uint32 col);
	~BadgeRenderer();
	void render(GameObject* o, Uint32 time);
};

