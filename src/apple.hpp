#pragma once
#include <SDL.h>
#include <random>
#include <cstdlib>
#include "render.hpp"

class Apple {
public:
	Apple();
	Apple(Render &render);
	void draw(Render& render);
	std::pair<int, int> getPos() { return std::pair<int, int>{x, y}; }
private:
	SDL_Texture* apple;
	int x, y;
};