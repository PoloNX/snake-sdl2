#include "game.hpp"

Game::Game() {
	running = true;
	keyState = key::none;
	Snake snake_temp(render);
	snake = std::move(snake_temp);
	apple = Apple(render);
	score = Score();
}

void Game::run() {

	while (running) {
		keyState = events.checkEvent();
		
		if (keyState == quit) {
			running = false;
		}

		snake.changeDirection(keyState);
		
		
		render.clear();
		apple.draw(render);
		current_collision = snake.checkPhysics(apple);
		score.draw(render);

		snake.move(render);
		manageCollisions();
		
		render.update();
		SDL_Delay(75);
	}
}

void Game::manageCollisions() {
	if (current_collision == collision::collision_apple) {
		score.addScore();
		snake.grow(render);
		apple = Apple(render);
	}
	else if (current_collision == collision::collision_snake || current_collision == collision::collision_wall) {
		SDL_Delay(1000);
		reset_game();
	}
}

void Game::reset_game() {
	score.resetScore();
	Snake snake_temp(render);
	snake = std::move(snake_temp);
}