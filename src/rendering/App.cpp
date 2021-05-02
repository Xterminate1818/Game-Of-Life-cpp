#include "App.h"

App::App(const int width, const int height) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	_frame_timer = Timer();
}

App::~App() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int App::getWidth() const {
	int w = 0;
	SDL_GetWindowSize(window, &w, nullptr);
	return w;
}

int App::getHeight() const {
	int h = 0;
	SDL_GetWindowSize(window, nullptr, &h);
	return h;
}

void App::addChild(GameObject* obj) {
	_children.push_back(obj);
	obj->_parent = this;
}

void App::draw() {
	// Clear Screen
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00); // Black
	SDL_RenderClear(renderer);

	// Draw elements
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
	for (GameObject* child : _children)
			child->draw();
	SDL_RenderPresent(renderer);
	_frame_timer.wait(_frame_time);
}

void App::handleEvent(const SDL_Event e) {
	for (GameObject* child : _children) {
		child->handleEvent(e);
	}
}

void App::start() {
	for (auto& obj : _children) {
		obj->init();
	}
	SDL_Event e;
	
	std::thread render_thread([](App* t) { t->startRenderLoop(); }, this);
	
	while (!_exit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				_exit = true;
			}
			handleEvent(e);
		}
		for (auto& obj : _children) {
			obj->process();
		}
	}
	render_thread.detach();
}

void App::startRenderLoop() {
	while (!_exit) {
		draw();
	}
}
