#include "App.h"

SDL_Window* App::window = nullptr;
SDL_Surface* App::screen = nullptr;
SDL_Renderer* App::renderer = nullptr;

const int App::width = 500;
const int App::height = 500;

void App::init(void) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void App::cleanup(void) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}