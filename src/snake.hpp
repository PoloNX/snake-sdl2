#pragma once
#include "events.hpp"
#include "render.hpp"
#include "apple.hpp"

enum orientation {IDLE, UP, DOWN, LEFT, RIGHT};
enum collision {no_collision, collision_apple, collision_snake, collision_wall};

class Snake {
public:
	Snake();
	Snake(Render& render_);
	void changeDirection(key keystate);
	void move(Render& render);
	void grow(Render& render);
	std::pair<int, int> getPos() { return std::pair<int, int>{body_vector[0].x, body_vector[0].y}; }
	collision checkPhysics(Apple& apple);
private:
	void draw(Render& render);
	SDL_Texture* snake_texture;
	orientation direction = IDLE;
	int length = -1;
	std::vector<SDL_Rect> body_vector;
	int screen_x;
	int screen_y;
};