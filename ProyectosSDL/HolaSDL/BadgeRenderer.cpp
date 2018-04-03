#include "BadgeRenderer.h"
#include "SDLGame.h"


BadgeRenderer::BadgeRenderer(SDLGame*game, Uint32 row, Uint32 col) : ImageRenderer(game->getResources()->getImageTexture(Resources::Badges), 3,3,row,col)
{
}


BadgeRenderer::~BadgeRenderer()
{
}

void BadgeRenderer::render(GameObject * o, Uint32 time)
{
	SDL_Rect rect
		RECT(o->getGame()->getWindowWidth() - clip_->w*2, 0,
			clip_->w*2, clip_->h*2);
	image_->render(o->getGame()->getRenderer(), rect, clip_);
}
