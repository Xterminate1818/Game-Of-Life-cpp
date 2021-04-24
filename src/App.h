#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "Timer.h"

typedef unsigned int LayerID;

class Drawable {
public:
	virtual void draw() = 0;
};

namespace App {
	extern SDL_Window* window;
	extern SDL_Surface* screen;
	extern SDL_Renderer* renderer;

	extern std::vector<Drawable*> _draw_queue;
	extern Timer _frameTimer;
	inline Uint32 frametime = 20;

	void add(Drawable*);
	void drawScreen();

	void init(int width, int height);
	void cleanup();
	int getWidth();
	int getHeight();
};

