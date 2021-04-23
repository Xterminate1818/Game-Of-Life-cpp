#pragma once
#include "../rendering/Drawable.h"

class Grid : public Drawable {
protected:
	bool* data = nullptr;
	virtual void draw();
	void drawGrid();
	int getIndex(int x, int y);
public:
	Grid(size_t width, size_t height);
	int gridWidth, gridHeight;
	bool get(int x, int y);
	void set(int x, int y, bool state);

	int getNeighbors(int x, int y);
	void step();
};