#include "Grid.h"

SDL_Event GRID_STEP = { SDL_RegisterEvents(1) };

Grid::Grid(const size_t width, const size_t height) {
	_data = new bool[width * height];
	_temp = new bool[width * height];
	
	for (int i = 0; i < width * height; i++) {
		_data[i] = false;
		_temp[i] = false;
	}
	this->width = width; 
	this->height = height;

	grid_width = 16;
	grid_height = 16;
}

constexpr size_t Grid::getIndex(size_t x, size_t y) const {
	x %= grid_width;
	y %= grid_height;
	return x + y * grid_height;
}

void Grid::draw() {
	const int cell_width = width / grid_width, cell_height = height / grid_height;
	// Draw grid lines
	for (int x = cell_width; x <= width; x += cell_width) {
		SDL_RenderDrawLine(_parent->renderer, 
			x, 0, x, height);
	}
	for (int y = cell_height; y <= height; y += cell_height) {
		SDL_RenderDrawLine(_parent->renderer, 
			0, y, width, y);
	}
	// Fill in grid
	SDL_Rect rect;
	for (int x = 0; x < grid_width; x++) {
		for (int y = 0; y < grid_height; y++) {
			if (get(x, y)) {
				rect = SDL_Rect {
					x * cell_width, y * cell_height, cell_width, cell_height
				};
				SDL_RenderFillRect(_parent->renderer, &rect);
			}
		}
	}
}

void Grid::handleEvent(const SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
		int x = 0, y = 0;
		SDL_GetMouseState(&x, &y);
		x /= _parent->getWidth() / grid_width;
		y /= _parent->getHeight() / grid_height;
		set(x, y, true);
	}
	if (e.type== SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
		step();
	}
}

bool Grid::get(const int x, const int y) const {
	return _data[getIndex(x, y)];
}

void Grid::set(const int x, const int y, const bool state) {
	_data[getIndex(x, y)] = state;
}

int Grid::getNeighbors(const int x, const int y) const {
	int n = 0;
	for (int ox = -1; ox <= 1; ox++) {
		for (int oy = -1; oy <= 1; oy++) {
			if (ox == 0 && oy == 0) {
				continue;
			}
			if (get(x + ox, y + oy)) {
				n += 1;
			}
		}
	}
	return n;
}

void Grid::step() {
	// Write new board state to temporary grid
	for (int x = 0; x < grid_width; x++) {
		for (int y = 0; y < grid_height; y++) {
			const int n = getNeighbors(x, y);
			if (get(x, y) && (n == 2 || n == 3) || !get(x, y) && n == 3) {
				_temp[x + y * grid_height] = true;
			}
			else {
				_temp[x + y * grid_height] = false;
			}
		}
	}

	// Swap grids
	bool* t = _data;
	_data = _temp;
	_temp = t;
}