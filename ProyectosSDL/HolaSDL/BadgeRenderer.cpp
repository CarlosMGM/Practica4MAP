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
	SDL_Rect rect;
	rect.h = SIZE;
	rect.w = SIZE;
	rect.x = o->getGame()->getWindowWidth() - SIZE;
	rect.y = 0;

	image_->render(o->getGame()->getRenderer(), rect, clip_);
}
