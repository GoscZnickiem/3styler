#include "move.hpp"

#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <random>

Move::Move(std::string label)
	:m_label(std::move(label)), m_axis(determineAxis(m_label)), m_layer(determineLayer(m_label)), m_amount(determineAmount(m_label)) {}

Move::Move(const std::string& m1, Axis a1, Axis a2) {
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrSide(0, 5);
	const char c = m1.empty() ? ' ' : m1.at(0);
	while(true) {
		switch (distrSide(gen)) {
			case 0:
				m_label = "R";
				break;
			case 1:
				m_label = "L";
				break;
			case 2:
				m_label = "U";
				break;
			case 3:
				m_label = "D";
				break;
			case 4:
				m_label = "F";
				break;
			case 5:
				m_label = "B";
				break;
			default: break;
		}
		m_axis = determineAxis(m_label);
		if(m_label.at(0) != c && (a1 != a2 || a1 != m_axis)) break;
	}
	m_layer = determineLayer(m_label);
    std::uniform_int_distribution<> distrAmount(0, 2);
	switch (distrAmount(gen)) {
			case 1:
				m_label += "'";
				break;
			case 2:
				m_label += "2";
				break;
			default: break;
	}
	m_amount = determineAmount(m_label);
}

Move::Axis Move::determineAxis(const std::string& label) {
	switch(std::toupper(label.at(0))) {
		case 'R':
		case 'L':
			return Axis::X;
		case 'U':
		case 'D':
			return Axis::Y;
		case 'F':
		case 'B':
			return Axis::Z;
		default:
			std::cerr << "Unknown move\n";
			return Axis::None;
	}
}

int Move::determineLayer(const std::string &label) {
	switch(label.at(0)) {
		case 'R':
		case 'U':
		case 'F':
			return 1;
		case 'L':
		case 'D':
		case 'B':
			return -1;
		default:
			std::cerr << "Unknown move\n";
			return 0;
	}
}

int Move::determineAmount(const std::string &label) {
	if(label.size() == 1)
		return 1;
	if(label.at(1) == 2)
		return 2;
	return 3;
}

Move::Axis Move::getAxis() const {
	return m_axis;
}

std::string Move::getName() const {
	return m_label;
}

int Move::getLayer() const {
	return m_layer;
}

int Move::getAmount() const {
	return m_amount;
}

std::string Move::toString() const {
	return m_label;
}

std::ostream& operator<< (std::ostream& os, const Move& s) {
	return os << s.m_label;
}
