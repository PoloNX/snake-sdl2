#pragma once
#include <SDL_ttf.h>
#include <string>
#include <format>
#include "render.hpp"

class Score {
public:
	Score();
	void addScore();
	void resetScore();
	void draw(Render& render);
	int getScore() { return score; }
private:
	int score;
	TTF_Font* font;
	SDL_Color textColor;
	SDL_Surface* text;
	SDL_Texture* texture;
};