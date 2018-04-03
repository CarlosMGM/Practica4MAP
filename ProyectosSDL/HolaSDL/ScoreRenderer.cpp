#include "ScoreRenderer.h"
#include"GameManager.h"


ScoreRenderer::ScoreRenderer()
{
}


ScoreRenderer::~ScoreRenderer()
{
}

void ScoreRenderer::render(GameObject * o, Uint32 time)
{
	Texture score(o->getGame()->getRenderer(),
			std::to_string(static_cast<GameManager*>(o)->getScore()),
			*(o->getGame()->getResources()->getFont(Resources::ARIAL24)), 
			{ COLOR(0x111122ff) });
	score.render(o->getGame()->getRenderer(), o->getGame()->getWindowWidth() / 2 - score.getWidth() / 2,
			10);
}
