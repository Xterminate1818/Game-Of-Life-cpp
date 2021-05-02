#pragma once
#include "../rendering/App.h" 
#include "GameObject.h"

extern SDL_Event GRID_STEP;

class Grid : public GameObject {
protected:
	bool* _data = nullptr;
	bool* _temp = nullptr;
	[[nodiscard]] constexpr size_t getIndex(size_t x, size_t y) const;
public:
	size_t width, height, grid_width, grid_height;
	
	Grid(size_t width, size_t height);
	void draw() override;
	void handleEvent(SDL_Event) override;
	[[nodiscard]] bool get(int x, int y) const;
	void set(int x, int y, bool state);
	[[nodiscard]] int getNeighbors(int x, int y) const;
	void step();
};