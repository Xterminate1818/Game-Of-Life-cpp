#include "Rect.h"

void Rect::draw() {
	if (color) SDL_SetRenderDrawColor(App::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	else SDL_SetRenderDrawColor(App::renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(App::renderer, this);
}

Rect::Rect(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->color = WHITE;
}
