#include "GameMsgRenderer.h"
#include "GameManager.h"


GameMsgRenderer::GameMsgRenderer()
{
}


GameMsgRenderer::~GameMsgRenderer()
{
}

void GameMsgRenderer::render(GameObject * o, Uint32 time)
{
	if (!static_cast<GameManager*>(o)->isRunning()) {
			Texture* enterKey = o->getGame()->getResources()->getTextTexture(
					Resources::PressEnter);
			enterKey->render(o->getGame()->getRenderer(),
				o->getGame()->getWindowWidth() / 2 - enterKey->getWidth() / 2,
				o->getGame()->getWindowHeight() - enterKey->getHeight() - 50);
	}
}
