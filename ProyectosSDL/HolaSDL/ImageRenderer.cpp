#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(Texture* image) : image_(image) {
}

ImageRenderer::ImageRenderer(Texture * image, Uint32 rows, Uint32 cols, Uint32 row, Uint32 col) : image_(image)
{
		clip_ = new SDL_Rect();
		clip_->h = image_->getHeight() / rows;
		clip_->w = image_->getWidth() / cols;
		clip_->x = clip_->w * col;
		clip_->y = clip_->h * row;
}

ImageRenderer::ImageRenderer(Texture* image, SDL_Rect*r) : image_(image) {
	clip_ = new SDL_Rect();
	clip_->h = r->h;
	clip_->w = r->w;
	clip_->x = r->x;
	clip_->y = r->y;
}

ImageRenderer::~ImageRenderer() {
	if (clip_ != nullptr)
		delete clip_;
}

void ImageRenderer::render(GameObject* o, Uint32 time) {
	SDL_Rect rect
			RECT(o->getPosition().getX(), o->getPosition().getY(),
					o->getWidth(), o->getHeight());
	image_->render(o->getGame()->getRenderer(), rect, -o->getDirection().angle(Vector2D(0,-1)), clip_);
//	image_->render(o->getGame()->getRenderer(), rect);
}
