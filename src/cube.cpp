#include "cube.hpp"

#include <iostream>

const std::string Cube::s_corners = "ABCDEFGHIJKLMNOPRSTUWXYZ";

Cube::Cube() :m_corners(s_corners) {}

void Cube::rotateCorners(int a1, int a2, int a3, int a4, int amount) {
	char c1 = ' ';
	char c2 = ' ';
	char c3 = ' ';
	char c4 = ' ';
	if (amount == 1) {
		c1 = m_corners.at(a2);
		c2 = m_corners.at(a3);
		c3 = m_corners.at(a4);
		c4 = m_corners.at(a1);
	} else if(amount == 2) {
		c1 = m_corners.at(a3);
		c2 = m_corners.at(a4);
		c3 = m_corners.at(a1);
		c4 = m_corners.at(a2);
	} else {
		c1 = m_corners.at(a4);
		c2 = m_corners.at(a1);
		c3 = m_corners.at(a2);
		c4 = m_corners.at(a3);
	}
	m_corners.at(a1) = c1;
	m_corners.at(a2) = c2;
	m_corners.at(a3) = c3;
	m_corners.at(a4) = c4;
}

void Cube::applyMove(const Move& move) {
	auto axis = move.getAxis();
	auto layer = move.getLayer();
	auto amount = move.getAmount();
	switch (axis) {
		case Move::Axis::X:
			if(layer == 1) {
				rotateCorners(12, 13, 14, 15, amount);
				rotateCorners(2, 16, 22, 10, amount);
				rotateCorners(1, 19, 21, 9, amount);
			} else if(layer == -1) {
				rotateCorners(4, 5, 6, 7, amount);
				rotateCorners(0, 8, 20, 18, amount);
				rotateCorners(3, 11, 23, 17, amount);
			} else {

			}
			break;
		case Move::Axis::Y:
			if(layer == 1) {
				rotateCorners(0, 1, 2, 3, amount);
				rotateCorners(4, 16, 12, 8, amount);
				rotateCorners(17, 13, 9, 5, amount);
			} else if(layer == -1) {
				rotateCorners(20, 21, 22, 23, amount);
				rotateCorners(6, 10, 14, 18, amount);
				rotateCorners(7, 11, 15, 19, amount);
			} else {

			}
			break;
		case Move::Axis::Z:
			if(layer == 1) {
				rotateCorners(8, 9, 10, 11, amount);
				rotateCorners(3, 12, 21, 6, amount);
				rotateCorners(5, 2, 15, 20, amount);
			} else if(layer == -1) {
				rotateCorners(16, 17, 18, 19, amount);
				rotateCorners(0, 7, 22, 13, amount);
				rotateCorners(1, 4, 23, 14, amount);
			} else {

			}
			break;
		default: std::cerr << "Unknown move\n";
	}
}

void Cube::applyScramble(const Scramble& scramble) {
	for(const Move& move : scramble.getMoves()) {
		applyMove(move);
		std::cout << toString() << "\n";
	}
}

std::string Cube::toString() const {
	return m_corners;
}
