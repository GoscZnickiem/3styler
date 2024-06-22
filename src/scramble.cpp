#include "scramble.hpp"

Scramble::Scramble(int length) {
	std::string last;
	Move::Axis a1 = Move::Axis::None;
	Move::Axis a2 = Move::Axis::None;
	for (int i = 0; i < length; i++) {
		m_moves.emplace_back(last, a1, a2);
		last = m_moves.back().getName();
		a2 = a1;
		a1 = m_moves.back().getAxis();
	}
}

std::string Scramble::toString() const {
	std::string s;
	bool first = true;
	for(const Move& m : m_moves) {
		if(!first) s += " ";
		s += m.toString();
		first = false;
	}
	return s;
}

std::ostream& operator<< (std::ostream& os, const Scramble& s) {
	return os << s.toString();
}
