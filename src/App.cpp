#include "App.h"

SDL_Window* App::window = nullptr;
SDL_Surface* App::screen = nullptr;
SDL_Renderer* App::renderer = nullptr;

std::vector<Drawable*> App::_draw_queue = std::vector<Drawable*>();
Timer App::_frameTimer = Timer();

void App::add(Drawable* d) {
	_draw_queue.push_back(d);
}

void App::drawScreen() {
	while (!_draw_queue.empty()) {
		Drawable* temp = _draw_queue[0];
		_draw_queue.pop_back();
		if (temp) {
			temp->draw();
		}
		else {
			std::cout << "Warning: nullpointer in draw queue" << std::endl;
		}
	}
	_frameTimer.wait(frametime);
}

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