#pragma once
#include <SDL.h>

enum key { none = -1, up, down, left, right, quit};

class Events {
public:
	Events();
	key checkEvent();
private:
	SDL_Event event;
};