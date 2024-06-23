#pragma once

#include "move.hpp"
#include "scramble.hpp"

#include <string>

class Cube {

public:
	Cube();

	void applyMove(const Move& move);

	void applyScramble(const Scramble& scramble);

	[[nodiscard]] std::string toString() const;

	void print() const;

private:
	void rotateCorners(int a1, int a2, int a3, int a4, int amount);
	void rotateEdges(int a1, int a2, int a3, int a4, int amount);

	std::string m_corners;
	std::string m_edges;

	static const std::string s_letterLayout;

};
