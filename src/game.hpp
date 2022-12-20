#pragma once
#include <SDL.h>
#include "render.hpp"
#include "events.hpp"
#include "snake.hpp"
#include "apple.hpp"
#include "score.hpp"

class Game {
public:
	Game();
	void run();
	void manageCollisions();
	void reset_game();
	bool isRunning() { return running; }
private:
	bool running = true;
	collision current_collision = collision::no_collision;
	key keyState;
	Render render;
	Events events;
	Snake snake;
	Apple apple;
	Score score;
};