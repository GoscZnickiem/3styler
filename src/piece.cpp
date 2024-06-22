#include "piece.hpp"
#include <string>
#include <utility>

Piece::Piece(int x, int y, int z, std::string letters)
	:m_position(x, y, z), m_letters(std::move(letters)) {}

void Piece::applyMove(const Move &move) {

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
