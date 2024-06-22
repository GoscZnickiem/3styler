#pragma once

#include "move.hpp"
#include <list>
#include <iostream>

class Scramble {

public:
	explicit Scramble(int length);

	// void addMove(const Move& move);

private:

	std::list<Move> m_moves;

	friend std::ostream& operator<< (std::ostream& os, const Scramble& s);
};

std::ostream& operator<< (std::ostream& os, const Scramble& s);
