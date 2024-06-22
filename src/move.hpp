#pragma once

#include <string>
#include <iostream>

class Move {

public:
	enum class Axis {
		None, X, Y, Z
	};

	explicit Move(std::string label);
	Move(const std::string& m1, Axis a1, Axis a2);

	[[nodiscard]] Axis determineAxis() const;

	[[nodiscard]] Axis getAxis() const;
	
	[[nodiscard]] std::string getName() const;

	[[nodiscard]] std::string toString() const;

private:

	std::string m_label;
	Axis m_axis;

	friend std::ostream& operator<< (std::ostream& os, const Move& s);
};

std::ostream& operator<< (std::ostream& os, const Move& s);
