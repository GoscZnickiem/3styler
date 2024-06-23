#pragma once

#include "move.hpp"

#include <list>
#include <iostream>
#include <string>

class Scramble {

public:
	explicit Scramble(int length);

	[[nodiscard]] const std::list<Move>& getMoves() const;

	[[nodiscard]] std::string toString() const;

private:

	std::list<Move> m_moves;

	friend std::ostream& operator<< (std::ostream& os, const Scramble& s);
};

std::ostream& operator<< (std::ostream& os, const Scramble& s);
