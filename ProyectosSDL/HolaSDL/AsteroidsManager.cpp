#include "AsteroidsManager.h"
#include "Texture.h"


AsteroidsManager::AsteroidsManager(SDLGame* game) : GameObject(game) 
{
	
	//Resources::getImageTexture(Resources::ImageId::Astroid);
}


AsteroidsManager::~AsteroidsManager(){
}

void AsteroidsManager::handleInput(Uint32 time, const SDL_Event & event)
{
}

void AsteroidsManager::update(Uint32 time)
{
}

void AsteroidsManager::render(Uint32 time)
{
}

vector<Asteroid*>& AsteroidsManager::getAstroids()
{
	return asteroids_;
}

void AsteroidsManager::receive(Message * msg)
{
}

Asteroid * AsteroidsManager::getAsteroid()
{
	return nullptr;
}

void AsteroidsManager::initAsteroids()
{
}
