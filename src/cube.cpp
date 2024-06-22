#include "cube.hpp"

const std::array<Piece, 8> Cube::s_corners = {
	Piece(-1,  1, -1, "123456"),
	Piece( 1,  1, -1, "123456"),
	Piece( 1,  1,  1, "123456"),
	Piece(-1,  1,  1, "123456"),
	Piece(-1, -1, -1, "123456"),
	Piece( 1, -1, -1, "123456"),
	Piece( 1, -1,  1, "123456"),
	Piece(-1, -1,  1, "123456")
};

Cube::Cube() :m_corners(s_corners) {}

void Cube::applyMove(const Move& move) {

}

void Cube::applyScramble(const Scramble& scramble) {

}
