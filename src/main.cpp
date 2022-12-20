#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "game.hpp"

void init();

int main() {
    init();
	
    Game game;
    game.run();
	
    return 0;
}

void init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
}