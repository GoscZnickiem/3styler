#include "scramble.hpp"

Scramble::Scramble(int length) {
	for (int i = 0; i < length; i++) {
		m_moves.emplace_back("R");
	}
}

std::ostream& operator<< (std::ostream& os, const Scramble& s) {
	for(const Move& m : s.m_moves) {
		os << m << " ";
	}
	return os << "\n";
}
