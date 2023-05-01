#pragma once
#include <iostream>
#include "wheel.h"

void clear_screen();

class Round {
	
public:
	int round;
	int prizes;
	std::string letter;

	Round() {
		round = 0;
		prizes = 0;
		letter = "";
	}

	void next_round(Wheel wheel) {
		round = (round + 1) % 3;
		prizes = wheel;
	}

	friend std::istream& operator>>(std::istream& is, Round& round) {
		std::string temp;
		is >> temp;

		while (temp.length() != 1)
		{	
			clear_screen();
			std::cout << std::endl << "Type a single letter and press <enter>: ";
			is >> temp;
		}

		round.letter = toupper(temp[0]);

		return is;
	}



};

void clear_screen() {
	std::cout << "\033[2J\033[1;1H";
}


