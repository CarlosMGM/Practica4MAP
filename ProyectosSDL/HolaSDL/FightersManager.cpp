#include "FightersManager.h"



FightersManager::FightersManager(SDLGame* game, Observer* bulletsManager): GameObject(game), fighter_(game, 1), accelerationComp_(SDLK_q, SDLK_w, 0.5, 5, 0.8),
	renderComp_(game->getResources()->getImageTexture(Resources::ImageId::Airplanes)), rotationComp_ (5, SDLK_o, SDLK_p), gunComp1_(5, SDLK_SPACE), gunComp2_(10000, SDLK_SPACE), badgeRenderer_(game_,1,1)
{
	gunComp1_.registerObserver(bulletsManager);
	gunComp2_.registerObserver(bulletsManager);

	fighter_.addInputComponent(& accelerationComp_);
	fighter_.addInputComponent(& rotationComp_);
	fighter_.addInputComponent(& gunComp1_);
	fighter_.addRenderComponent(& renderComp_);
	fighter_.addPhysicsComponent(& circulrMotoionComp_);
}


FightersManager::~FightersManager()
{
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
		fighter_.setActive(true);
		fighter_.setVelocity({0.0, 0.0});
		fighter_.setPosition( Vector2D( game_->getWindowWidth() / 2, game_->getWindowHeight() / 2));
			break;
	case ROUND_OVER:
		fighter_.setActive(false);
			break;
	case BADGE_ON:
		if (!badgeState) {
			fighter_.delInputComponent(&gunComp1_);
			fighter_.addInputComponent(&gunComp2_);
			fighter_.addRenderComponent(&badgeRenderer_);
			badgeState = true;
		}
			break;
	case BADGE_OFF:
		if (badgeState) {
			fighter_.delInputComponent(&gunComp2_);
			fighter_.addInputComponent(&gunComp1_);
			fighter_.delRenderComponent(&badgeRenderer_);
			badgeState = false;
		}
			break;
	}
}