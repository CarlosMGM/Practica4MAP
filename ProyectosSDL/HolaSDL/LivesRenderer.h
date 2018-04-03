#pragma once
#include "ImageRenderer.h"

class LivesRenderer :
	public ImageRenderer
{
public:
	LivesRenderer(SDLGame*game);
	~LivesRenderer();
	void render(GameObject* o, Uint32 time);
};

