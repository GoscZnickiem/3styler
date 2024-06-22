#pragma once

#include <string>
#include <iostream>

class Move {

public:
	explicit Move(std::string label);

private:

	std::string m_label;

	friend std::ostream& operator<< (std::ostream& os, const Move& s);
};

std::ostream& operator<< (std::ostream& os, const Move& s);
