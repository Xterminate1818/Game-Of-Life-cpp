#include "Grid.h"

SDL_Event GRID_STEP = { SDL_RegisterEvents(1) };

Grid::Grid(size_t width, size_t height) {
	data = new bool[width * height];
	for (int i = 0; i < width * height; i++)
		data[i] = false;
	gridWidth = width; 
	gridHeight = height;
}

int Grid::getIndex(int x, int y) {
	x %= gridWidth;
	y %= gridHeight;
	while (x < 0) x += gridWidth;
	while (y < 0) y += gridHeight;
	return x + y * gridHeight;
}

void Grid::drawGrid() {
	int width = App::getWidth(), height = App::getHeight();
	int cellWidth = width / gridWidth, cellHeight = height / gridHeight;
	// Draw grid lines
	for (int x = cellWidth; x <= width; x += cellWidth) {
		SDL_RenderDrawLine(App::renderer, x, 0, x, height);
	}
	for (int y = cellHeight; y <= height; y += cellHeight) {
		SDL_RenderDrawLine(App::renderer, 0, y, width, y);
	}
	// Fill in grid
	SDL_Rect rect;
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			if (get(x, y)) {
				rect = SDL_Rect{ x * cellWidth, y * cellHeight, cellWidth, cellHeight };
				SDL_RenderFillRect(App::renderer, &rect);
			}
		}
	}
}

void Grid::draw() {
	drawGrid();
}

bool Grid::get(int x, int y) {
	return data[getIndex(x, y)];
}

void Grid::set(int x, int y, bool state) {
	data[getIndex(x, y)] = state;
}

int Grid::getNeighbors(int x, int y) {
	int n = 0;
	for (int ox = -1; ox <= 1; ox++) {
		for (int oy = -1; oy <= 1; oy++) {
			if (ox == 0 && oy == 0) {
				continue;
			}
			if (get(x + ox, y + oy)) {
				n += 1;
				n = n;
			}
		}
	}
	return n;
}

void Grid::step() {
	// Copy array
	bool* newdata = new bool[(size_t)gridWidth * (size_t)gridHeight];
	for (int i = 0; i < gridWidth * gridHeight; i++) newdata[i] = data[i];

	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			int n = getNeighbors(x, y);
			if (get(x, y) && (n == 2 || n == 3)) newdata[x + y * gridHeight] = true;
			else if (!get(x, y) && n == 3) newdata[x + y * gridHeight] = true;
			else newdata[x + y * gridHeight] = false;
		}
	}
	delete[] data;
	data = newdata;
}