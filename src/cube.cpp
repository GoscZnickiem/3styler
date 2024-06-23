#include "cube.hpp"

#include <iostream>

// const std::string Cube::s_letterLayout = "ABCDEFGHIJKLMNOPRSTUWXYZ";
const std::string Cube::s_letterLayout = "WWWWOOOOGGGGRRRRBBBBYYYY";

Cube::Cube() :m_corners(s_letterLayout), m_edges(s_letterLayout) {}

void Cube::rotateCorners(int a1, int a2, int a3, int a4, int amount) {
	char c1 = ' ';
	char c2 = ' ';
	char c3 = ' ';
	char c4 = ' ';
	if (amount == 1) {
		c1 = m_corners.at(a4);
		c2 = m_corners.at(a1);
		c3 = m_corners.at(a2);
		c4 = m_corners.at(a3);
	} else if(amount == 2) {
		c1 = m_corners.at(a3);
		c2 = m_corners.at(a4);
		c3 = m_corners.at(a1);
		c4 = m_corners.at(a2);
	} else {
		c1 = m_corners.at(a2);
		c2 = m_corners.at(a3);
		c3 = m_corners.at(a4);
		c4 = m_corners.at(a1);
	}
	m_corners.at(a1) = c1;
	m_corners.at(a2) = c2;
	m_corners.at(a3) = c3;
	m_corners.at(a4) = c4;
}

void Cube::rotateEdges(int a1, int a2, int a3, int a4, int amount) {
	char c1 = ' ';
	char c2 = ' ';
	char c3 = ' ';
	char c4 = ' ';
	if (amount == 1) {
		c1 = m_edges.at(a4);
		c2 = m_edges.at(a1);
		c3 = m_edges.at(a2);
		c4 = m_edges.at(a3);
	} else if(amount == 2) {
		c1 = m_edges.at(a3);
		c2 = m_edges.at(a4);
		c3 = m_edges.at(a1);
		c4 = m_edges.at(a2);
	} else {
		c1 = m_edges.at(a2);
		c2 = m_edges.at(a3);
		c3 = m_edges.at(a4);
		c4 = m_edges.at(a1);
	}
	m_edges.at(a1) = c1;
	m_edges.at(a2) = c2;
	m_edges.at(a3) = c3;
	m_edges.at(a4) = c4;
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
				rotateEdges(12, 13, 14, 15, amount);
				rotateEdges(1, 19, 21, 9, amount);
			} else if(layer == -1) {
				rotateCorners(4, 5, 6, 7, amount);
				rotateCorners(0, 8, 20, 18, amount);
				rotateCorners(3, 11, 23, 17, amount);
				rotateEdges(4, 5, 6, 7, amount);
				rotateEdges(3, 11, 23, 17, amount);
			} else {
				rotateEdges(0, 18, 20, 8, amount);
				rotateEdges(3, 16, 22, 10, amount);
			}
			break;
		case Move::Axis::Y:
			if(layer == 1) {
				rotateCorners(0, 1, 2, 3, amount);
				rotateCorners(4, 16, 12, 8, amount);
				rotateCorners(17, 13, 9, 5, amount);
				rotateEdges(0, 1, 2, 3, amount);
				rotateEdges(16, 12, 8, 4, amount);
			} else if(layer == -1) {
				rotateCorners(20, 21, 22, 23, amount);
				rotateCorners(6, 10, 14, 18, amount);
				rotateCorners(7, 11, 15, 19, amount);
				rotateEdges(20, 21, 22, 23, amount);
				rotateEdges(6, 10, 14, 18, amount);
			} else {
				rotateEdges(5, 9, 13, 17, amount);
				rotateEdges(7, 11, 15, 19, amount);
			}
			break;
		case Move::Axis::Z:
			if(layer == 1) {
				rotateCorners(8, 9, 10, 11, amount);
				rotateCorners(3, 12, 21, 6, amount);
				rotateCorners(5, 2, 15, 20, amount);
				rotateEdges(8, 9, 10, 11, amount);
				rotateEdges(2, 15, 20, 5, amount);
			} else if(layer == -1) {
				rotateCorners(16, 17, 18, 19, amount);
				rotateCorners(0, 7, 22, 13, amount);
				rotateCorners(1, 4, 23, 14, amount);
				rotateEdges(16, 17, 18, 19, amount);
				rotateEdges(0, 7, 22, 13, amount);
			} else {
				rotateEdges(1, 14, 23, 4, amount);
				rotateEdges(3, 12, 21, 6, amount);
			}
			break;
		default: std::cerr << "Unknown move\n";
	}
}

void Cube::applyScramble(const Scramble& scramble) {
	for(const Move& move : scramble.getMoves()) {
		applyMove(move);
		std::cout << move.toString() << ":\n";
		print();
		std::cout << "\n" << toString() << "\n";
	}
}

void Cube::print() const {
	std::cout << "    " << m_corners.at(0) << m_edges.at(0) << m_corners.at(1) << "\n";
	std::cout << "    " << m_edges.at(3) << "*" << m_edges.at(1) << "\n";
	std::cout << "    " << m_corners.at(3) << m_edges.at(2) << m_corners.at(2) << "\n";

	std::cout << m_corners.at(4) << m_edges.at(4) << m_corners.at(5) << " ";
	std::cout << m_corners.at(8) << m_edges.at(8) << m_corners.at(9) << " ";
	std::cout << m_corners.at(12) << m_edges.at(12) << m_corners.at(13) << " ";
	std::cout << m_corners.at(16) << m_edges.at(16) << m_corners.at(17) << "\n";

	std::cout << m_edges.at(7) << "*" << m_edges.at(5) << " ";
	std::cout << m_edges.at(11) << "*" << m_edges.at(9) << " ";
	std::cout << m_edges.at(15) << "*" << m_edges.at(13) << " ";
	std::cout << m_edges.at(19) << "*" << m_edges.at(17) << "\n";

	std::cout << m_corners.at(7) << m_edges.at(6) << m_corners.at(6) << " ";
	std::cout << m_corners.at(11) << m_edges.at(10) << m_corners.at(10) << " ";
	std::cout << m_corners.at(15) << m_edges.at(14) << m_corners.at(14) << " ";
	std::cout << m_corners.at(19) << m_edges.at(18) << m_corners.at(18) << "\n";

	std::cout << "    " << m_corners.at(20) << m_edges.at(20) << m_corners.at(21) << "\n";
	std::cout << "    " << m_edges.at(23) << "*" << m_edges.at(21) << "\n";
	std::cout << "    " << m_corners.at(23) << m_edges.at(22) << m_corners.at(22) << "\n";
}

std::string Cube::toString() const {
	return m_corners + " " + m_edges;
}
