#include "render.hpp"

Render::Render() {
	width = 800;
	height = 600;
	window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void Render::draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, int r, int g, int b, int a) {
	SDL_RenderCopy(renderer, texture, src, dest);
	return;
}

void Render::update() {
	SDL_RenderPresent(renderer);
}

void Render::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

Render::~Render() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}