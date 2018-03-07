#ifndef IMAGERENDERER_H_
#define IMAGERENDERER_H_
#include <SDL.h>
#include "RenderComponent.h"

/*
 *
 */
class ImageRenderer: public RenderComponent {
public:
	ImageRenderer(Texture* image);
	ImageRenderer(Texture* image, Uint32 rows, Uint32 cols, Uint32 row, Uint32 col);
	ImageRenderer(Texture * image, SDL_Rect*r);
	virtual ~ImageRenderer();
	virtual void render(GameObject* o, Uint32 time);
private:
	Texture* image_;
	SDL_Rect * clip_ = nullptr;
};

#endif /* IMAGERENDERER_H_ */
