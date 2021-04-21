#pragma once
#include "../rendering/Drawable.h"

typedef bool Color;
const Color BLACK = false;
const Color WHITE = true;

class Rect : public Drawable, public SDL_Rect {
protected:
	virtual void draw();
public:
	Color color;
	Rect(int x, int y, int w, int h);
};
