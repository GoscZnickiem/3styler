#pragma once

#include "move.hpp"

class Vec {

public:
	explicit Vec(int x = 0, int y = 0, int z = 0);

	void rotate(Move::Axis axis, int amount);

private:
	int x;
	int y;
	int z;
};
