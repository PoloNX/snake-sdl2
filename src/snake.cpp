#include "snake.hpp"
#include <iostream>


Snake::Snake()
{
	
}

Snake::Snake(Render& render) 
{
	screen_x = render.getSize().first;
	screen_y = render.getSize().second;
	
	SDL_SetRenderDrawColor(render.getRenderer(), 0, 255, 0, 255);
	snake_texture = SDL_CreateTexture(render.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 15, 15);
	SDL_Rect rect{ 0, 0, 15, 15 };
	SDL_SetRenderTarget(render.getRenderer(), snake_texture);
	SDL_RenderFillRect(render.getRenderer(), &rect);
	SDL_SetRenderTarget(render.getRenderer(), NULL);

	SDL_Rect rect_head{ 45, 45, 15, 15 };
	
	body_vector.push_back(rect_head);

}

collision Snake::checkPhysics(Apple& apple)
{	
	if (body_vector[0].x == apple.getPos().first && body_vector[0].y == apple.getPos().second)
	{
		return collision::collision_apple;
	}
	else if (body_vector[0].x < 0 || body_vector[0].x >= screen_x || body_vector[0].y < 0 || body_vector[0].y >= screen_y)
	{
		return collision::collision_wall;
	}
	else if (body_vector.size() > 0) {
		for (auto i = 1; i < body_vector.size(); ++i) {
			if (body_vector[0].x == body_vector[i].x && body_vector[0].y == body_vector[i].y) {
				return collision::collision_snake;
			}
		}
	}
	
	return collision::no_collision;

}

void Snake::changeDirection(key keystate) {
	if (keystate == key::up) {
		if (direction != DOWN) {
			direction = UP;
		}
		else {
			direction = DOWN;
		}
	}
	else if (keystate == key::down) {
		if (direction != UP) {
			direction = DOWN;
		}
		else {
			direction = UP;
		}
	}
	else if (keystate == key::left) {
		if (direction != RIGHT) {
			direction = LEFT;
		}
		else {
			direction = RIGHT;
		}
	}
	else if (keystate == key::right) {
		if (direction != LEFT) {
			direction = RIGHT;
		}
		else {
			direction = LEFT;
		}
	}
}

void Snake::draw(Render& render) {
	
	for (int i = 0; i < body_vector.size(); i++)
	{
		render.draw(snake_texture, nullptr, &body_vector[i]);
	}
}


void Snake::move(Render& render) {
	draw(render);
	
	std::vector<SDL_Rect> rect_temp;
	rect_temp = body_vector;
	
	for (auto i = 1; i < body_vector.size(); i++)
	{
		rect_temp[i].x = body_vector[i - 1].x;
		rect_temp[i].y = body_vector[i - 1].y;
	}

	body_vector = rect_temp;
	
	switch (direction) {
	case orientation::IDLE:
		break;
	case orientation::UP:
		body_vector[0].y -= 15;
		break;
	case orientation::DOWN:
		body_vector[0].y += 15;
		break;
	case orientation::LEFT:
		body_vector[0].x -= 15;
		break;
	case orientation::RIGHT:
		body_vector[0].x += 15;
		break;
	}
}

void Snake::grow(Render& render) {
	++length;
	SDL_Rect rect{ body_vector[body_vector.size()].x - 15, body_vector[body_vector.size()].y - 15, 15, 15};
	body_vector.push_back(rect);
}