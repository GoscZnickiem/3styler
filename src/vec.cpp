#include "vec.hpp"
#include <iostream>

Vec::Vec(int x, int y, int z) :x(x), y(y), z(z) {}

void rot(int& a, int& b, int r) {
	int ax = (1 - r) * b + (r - 1) * (r - 3) * a;
	int bx = (r - 1) * a - (r - 1) * (r - 3) * b;
	a = ax; 
	b = bx;
}

void Vec::rotate(Move::Axis axis, int amount) {
	switch (axis) {
		case Move::Axis::X:
			rot(y, z, amount);
			break;
		case Move::Axis::Y:
			rot(z, x, amount);
			break;
		case Move::Axis::Z:
			rot(x, y, amount);
			break;
		default:
			std::cerr << "unknown axis\n";
	}
}
