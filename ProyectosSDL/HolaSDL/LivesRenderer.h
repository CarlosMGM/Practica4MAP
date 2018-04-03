#pragma once
#include "ImageRenderer.h"
#define SIZE 40
class LivesRenderer :
	public ImageRenderer
{
public:
	LivesRenderer(SDLGame*game);
	~LivesRenderer();
	void render(GameObject* o, Uint32 time);
};

