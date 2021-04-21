#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <memory>

class App {
public:
	static const int width, height;
	static SDL_Window* window;
	static SDL_Surface* screen;
	static SDL_Renderer* renderer;

	static void init();
	static void cleanup();
};