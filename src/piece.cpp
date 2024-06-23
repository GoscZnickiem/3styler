#include "piece.hpp"
#include <string>
#include <utility>

Piece::Piece(int x, int y, int z, std::string letters)
	:m_position(x, y, z), m_letters(std::move(letters)) {}

void rot(char& a1, char& a2, char& a3, char& a4, int amount) {
	char n1 = 0; char n2 = 0; char n3 = 0; char n4 = 0;
	if(amount == 1) {
		n1 = a4;
		n2 = a1;
		n3 = a2;
		n4 = a3;
	} else if(amount == 2) {
		n1 = a3;
		n2 = a4;
		n3 = a1;
		n4 = a2;
	} else {
		n1 = a2;
		n2 = a3;
		n3 = a4;
		n4 = a1;
	}
	a1 = n1;
	a2 = n2;
	a3 = n3;
	a4 = n4;
}

void Piece::applyMove(const Move &move) {
	Move::Axis axis = move.getAxis();
	int amount = move.getAmount();
	m_position.rotate(axis, amount);
	switch (axis) {
		case Move::Axis::X:
			rot(m_letters.at(0), m_letters.at(6), m_letters.at(1), m_letters.at(4), amount);
			break;
		case Move::Axis::Y:
			rot(m_letters.at(2), m_letters.at(4), m_letters.at(3), m_letters.at(5), amount);
			break;
		case Move::Axis::Z:
			rot(m_letters.at(0), m_letters.at(2), m_letters.at(1), m_letters.at(3), amount);
			break;
		default:
			std::cerr << "unknown axis\n";
	}
}

void Piece::emplace(int x, int y, int z) {

}

void Piece::emplace(const Vec& pos) {

}

void Piece::setPosition(int x, int y, int z) {

}

void Piece::setPosition(const Vec& v) {

}

Vec Piece::getPosition() const {
	return m_position;
}
