#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <queue>
#include <iostream>
#include "App.h"

typedef unsigned int LayerID;



class Drawable {
	class Compare {
	public:
		bool operator() (const Drawable* a, const Drawable* b);
	};
protected:
	static std::priority_queue<Drawable*, std::vector<Drawable*>, Compare> m_render_queue;
	virtual void draw() = 0;
public:
	static Uint32 WHITE;
	static Uint32 BLACK;
	static void add(Drawable* d);
	static void drawScreen();
	LayerID layer = 0;
};


