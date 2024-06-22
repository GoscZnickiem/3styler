#pragma once

#include "move.hpp"
#include "vec.hpp"
#include <string>

class Piece {

public:
	Piece(int x, int y, int z, std::string letters);

	void applyMove(const Move &move);

	void emplace(int x, int y, int z);
	void emplace(const Vec& pos);

	void setPosition(int x, int y, int z);
	void setPosition(const Vec& v);

	[[nodiscard]] Vec getPosition() const;

private:
	Vec m_position;
	std::string m_letters;

};
