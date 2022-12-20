#include "apple.hpp"

Apple::Apple(Render& render) {
	srand(time(0));

	x = rand() % (render.getSize().first/15)*15;
	y = rand() % (render.getSize().second/15)*15;

	if (x < 0 || x > render.getSize().first) {
		x = rand() % (render.getSize().first / 15) * 15;
	}

	if (y < 0 || y > render.getSize().second) {
		y = rand() % (render.getSize().second / 15) * 15;
	}
}

Apple::Apple() {

}

void Apple::draw(Render& render) {
	SDL_Rect dst = { x, y, 15, 15 };

	SDL_SetRenderDrawColor(render.getRenderer(), 255, 0, 0, 255);
	apple = SDL_CreateTexture(render.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 15, 15);
	SDL_Rect rect{ 0, 0, 15, 15 };
	SDL_SetRenderTarget(render.getRenderer(), apple);
	SDL_RenderFillRect(render.getRenderer(), &rect);
	SDL_SetRenderTarget(render.getRenderer(), NULL);

	render.draw(apple, NULL, &dst, 0, 255, 0, 255);
	SDL_DestroyTexture(apple);
}