#include "score.hpp"
#include <iostream>

Score::Score() {
	score = 0;
	font = TTF_OpenFont("res/arial.ttf", 30);
	textColor = { 255, 255, 255 };
}

SDL_Point getsize(SDL_Texture* texture) {
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	return size;
}

void Score::addScore() {
	score++;
}

void Score::resetScore() {
	score = 0;
}
void Score::draw(Render& render) {
	
	text = TTF_RenderText_Blended(font, std::format("Score : {}", score).c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(render.getRenderer(), text);
	SDL_Rect rect{ render.getSize().first / 2 - getsize(texture).x / 2 , 0, getsize(texture).x, getsize(texture).y};	
	render.draw(texture, nullptr, &rect);
	SDL_FreeSurface(text);
	SDL_DestroyTexture(texture);
}



