#include "Transform.h"

Transform::Transform(const int x, const int y) : x_offset(x), y_offset(y) {}

Vector Transform::convert(const Vector& vec) const {
	return Vector { vec.x + x_offset, vec.y + y_offset };
}
