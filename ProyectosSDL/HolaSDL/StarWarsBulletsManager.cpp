#include "StarWarsBulletsManager.h"
#include "FillRectRenderer.h"
#include "BasicMotionPhysics.h"
#include "GameComponent.h"
StarWarsBulletsManager::StarWarsBulletsManager(SDLGame*g) : GameObject(g)
{
	bullets = new std::vector<GameObject*>();
}


StarWarsBulletsManager::~StarWarsBulletsManager()
{
	while (!bullets->empty()) {
		delete bullets->back();
		bullets->pop_back();
	}
	delete bullets;
}

void StarWarsBulletsManager::shoot(GameObject * o, Vector2D p, Vector2D v)
{
	GameComponent * comp = new GameComponent(game_);
	comp->addRenderComponent(new FillRectRenderer());
	comp->addPhysicsComponent(new BasicMotionPhysics());

	comp->setHeight(2);
	comp->setWidth(2);
	comp->setPosition(p);
	comp->setVelocity(v);

	bullets->push_back(comp);
}

void StarWarsBulletsManager::update(Uint32 time)
{
	std::vector<GameObject*>::iterator it = bullets->begin();
	while (it != bullets->end()) {
		(*it)->update(time);
		Vector2D p = (*it)->getPosition();
		if (p.getX() < 0 || p.getX() > game_->getWindowWidth() || p.getY() < 0 || p.getY() > game_->getWindowHeight()) {
			delete (*it);
			it = bullets->erase(it);
		}
		if(it != bullets->end())
			it++;
	}
}

void StarWarsBulletsManager::render(Uint32 time)
{
	for (int i = 0; i < bullets->size(); i++)
		(*bullets)[i]->render(time);

}

void StarWarsBulletsManager::handleInput(Uint32 time, const SDL_Event & event)
{
}


