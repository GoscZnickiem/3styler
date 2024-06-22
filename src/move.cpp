#include "move.hpp"

#include <utility>

Move::Move(std::string label)
	: m_label(std::move(label)) {}

std::ostream& operator<< (std::ostream& os, const Move& s) {
	return os << s.m_label;
}
