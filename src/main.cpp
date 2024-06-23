#include "cube.hpp"
#include "scramble.hpp"

#include <iostream>
#include <ncurses.h>

int main() {
	// initscr();
	// raw();
	// noecho();
	// keypad(stdscr,TRUE);
	//
	// mvprintw(2, 3, "Option 1");
	// mvprintw(3, 3, "Option 2");
	// mvprintw(4, 3, "Exit");
	// move(2, 3);
	//
	// getch();
	//
	// refresh();
	//
	// endwin();
	const Scramble s(18);

	std::cout << "skrambel:\n" << s << "\n";

	Cube cube;

	cube.applyScramble(s);

}
