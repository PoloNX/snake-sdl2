#pragma once
#include <SDL.h>
#include <utility>

class Render {
public:
	Render();
	~Render();
	void draw(SDL_Texture* texture, SDL_Rect* src = nullptr, SDL_Rect* dest = nullptr, int r = 0, int g = 0, int b = 0, int a = 255);
	void update();
	void handleEvents();
	void clear();
	SDL_Renderer* getRenderer() { return renderer; }
	std::pair<int, int> getSize() { return std::pair<int, int>(width, height); }
private:
	int width, height;
	SDL_Window *window;
	SDL_Renderer *renderer;
};