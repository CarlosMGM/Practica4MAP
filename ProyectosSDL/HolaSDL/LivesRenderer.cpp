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
	SDL_Rect rect
		RECT(0, 0, clip_->w, clip_->h);
	for (int i = 0; i < static_cast<GameManager*>(o)->getLives(); i++, rect.x += clip_->w)
		image_->render(o->getGame()->getRenderer(), rect, clip_);
}
