#include "App.h"

SDL_Window* App::window = nullptr;
SDL_Surface* App::screen = nullptr;
SDL_Renderer* App::renderer = nullptr;

void App::init(int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void App::cleanup(void) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int App::getWidth() {
	int w = 0;
	SDL_GetWindowSize(window, &w, nullptr);
	return w;
}

int App::getHeight() {
	int h = 0;
	SDL_GetWindowSize(window, nullptr, &h);
	return h;
}