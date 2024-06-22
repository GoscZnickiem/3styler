#pragma once

#include "piece.hpp"
#include "move.hpp"
#include "scramble.hpp"

#include <array>

class Cube {

public:
	Cube();

	void applyMove(const Move& move);

	void applyScramble(const Scramble& scramble);

private:
	std::array<Piece, 8> m_corners;

	static const std::array<Piece, 8> s_corners;

};
