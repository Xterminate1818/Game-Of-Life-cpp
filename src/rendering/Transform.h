#pragma once
#include <cstdint>
#include <SDL.h>

struct Vector {
	int x, y;
};

class Transform {
public:
	int x_offset, y_offset;
	Transform(int x, int y);
	[[nodiscard]] Vector convert(const Vector&) const;
};

