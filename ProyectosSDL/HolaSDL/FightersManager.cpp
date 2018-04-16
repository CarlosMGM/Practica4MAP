#include "FightersManager.h"



FightersManager::FightersManager(SDLGame* game, Observer* bulletsManager): GameObject(game), fighter_(game, 1), accelerationComp_(SDLK_q, SDLK_w, 0.5, 5, 0.8),
	renderComp_(game->getResources()->getImageTexture(Resources::ImageId::Airplanes)), rotationComp_ (5, SDLK_o, SDLK_p), badgeRenderer_(game_,1,1), gunComp(5, 0, SDLK_SPACE)
{
	gunComponents.push_back(new GunInputComponent(1000, 0, SDLK_SPACE));
	gunComponents.push_back(new GunInputComponent(5, 1, SDLK_SPACE));
	gunComponents.push_back(new GunInputComponent(5, 2, SDLK_SPACE));
	
	

	gunComp.registerObserver(bulletsManager);
	for ( int i = 0;  i < gunComponents.size(); i++)
	{
		gunComponents[i]->registerObserver(bulletsManager);
	}

	fighter_.addInputComponent(& accelerationComp_);
	fighter_.addInputComponent(& rotationComp_);
	fighter_.addInputComponent(&gunComp);
	fighter_.addRenderComponent(& renderComp_);
	fighter_.addPhysicsComponent(& circulrMotoionComp_);
}


FightersManager::~FightersManager()
{
	for each (GunInputComponent* var in gunComponents)
	{
		delete var;
	}
}

void FightersManager::handleInput(Uint32 time, const SDL_Event& event) {
	if (fighter_.isActive())
		fighter_.handleInput(time, event);
}

void FightersManager::update(Uint32 time) {
	if (fighter_.isActive())
		fighter_.update(time);
}

void FightersManager::render(Uint32 time) {
	if (fighter_.isActive())
		fighter_.render(time);
}

Fighter* FightersManager::getFighter() {
	return & fighter_;

}

void FightersManager::receive(Message* msg) {
	switch (msg->id_) {
	case ROUND_START:
		counter = 0;
		fighter_.setActive(true);
		fighter_.setVelocity({0.0, 0.0});
		fighter_.setPosition( Vector2D( game_->getWindowWidth() / 2, game_->getWindowHeight() / 2));
			break;
	case ROUND_OVER:
		fighter_.setActive(false);
			break;
	case BADGE_ON:
		if (!badgeState) {
 			fighter_.delInputComponent(&gunComp);
			fighter_.addInputComponent(gunComponents[counter]);
			fighter_.addRenderComponent(&badgeRenderer_);
			badgeState = true;
		}
			break;
	case BADGE_OFF:
		if (badgeState) {
			fighter_.delInputComponent(gunComponents[counter]);
			fighter_.addInputComponent(&gunComp);
			fighter_.delRenderComponent(&badgeRenderer_);
			counter = (counter + 1) % 3;
			badgeState = false;
		}
			break;
	}
}