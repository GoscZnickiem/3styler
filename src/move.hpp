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

	[[nodiscard]] static Axis determineAxis(const std::string& label);

	[[nodiscard]] static int determineLayer(const std::string& label);

	[[nodiscard]] static int determineAmount(const std::string& label);

	[[nodiscard]] Axis getAxis() const;
	
	[[nodiscard]] std::string getName() const;

	[[nodiscard]] int getLayer() const;
	
	[[nodiscard]] int getAmount() const;

	[[nodiscard]] std::string toString() const;

private:

	std::string m_label;
	Axis m_axis;
	int m_layer;
	int m_amount;

	friend std::ostream& operator<< (std::ostream& os, const Move& s);
};

std::ostream& operator<< (std::ostream& os, const Move& s);
