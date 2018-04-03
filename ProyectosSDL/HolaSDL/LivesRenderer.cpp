#include "LivesRenderer.h"
#include "SDLGame.h"
#include "GameManager.h"

LivesRenderer::LivesRenderer(SDLGame*game) : ImageRenderer(game->getResources()->getImageTexture(Resources::Badges), 3, 3, 2, 2)
{
}


LivesRenderer::~LivesRenderer()
{
}


void LivesRenderer::render(GameObject * o, Uint32 time)
{

	SDL_Rect rect;
	rect.h = SIZE;
	rect.w = SIZE;
	rect.x = rect.y = 0;
	for (int i = 0; i < static_cast<GameManager*>(o)->getLives(); i++, rect.x += SIZE)
		image_->render(o->getGame()->getRenderer(), rect, clip_);
}
