#include "events.hpp"
#include <iostream>
Events::Events() {
	
}

key Events::checkEvent() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return key::quit;
		}
		
		else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					std::cout << "UP" << std::endl;
					return key::up;
					break;
				case SDLK_DOWN:
					std::cout << "DOWN" << std::endl;
					return key::down;
					break;
				case SDLK_LEFT:
					std::cout << "LEFT" << std::endl;
					return key::left;
					break;
				case SDLK_RIGHT:
					std::cout << "RIGHT" << std::endl;
					return key::right;
					break;
			}
		}
	}
	return key::none;
}