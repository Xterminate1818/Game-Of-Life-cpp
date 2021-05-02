#pragma once
#include <vector>
#include <thread>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include "../util/Timer.h"
#include "../entity/GameObject.h"

typedef unsigned int LayerID;

class App final {
protected:
	std::vector<GameObject*> _children;
	Timer _frame_timer;
	Uint32 _frame_time = 20;
	bool _exit = false;
	
public:
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;

	void addChild(GameObject*);
	void draw();
	void handleEvent(SDL_Event);
	void start();

	void startRenderLoop();

	App(int width, int height);
	~App();
	[[nodiscard]] int getWidth() const;
	[[nodiscard]] int getHeight() const;
};
