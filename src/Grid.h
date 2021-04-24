#pragma once
#include "App.h"

extern SDL_Event GRID_STEP;

class Grid : public Drawable {
protected:
	bool* data = nullptr;
	void drawGrid();
	int getIndex(int x, int y);
public:
	virtual void draw();
	Grid(size_t width, size_t height);
	int gridWidth, gridHeight;
	bool get(int x, int y);
	void set(int x, int y, bool state);

	int getNeighbors(int x, int y);
	void step();
};