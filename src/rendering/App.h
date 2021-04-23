#pragma once
#include <SDL.h>
#include <SDL_image.h>

class App {
public:
	static SDL_Window* window;
	static SDL_Surface* screen;
	static SDL_Renderer* renderer;

	static void init(int width, int height);
	static void cleanup();
	static int getWidth();
	static int getHeight();
};