#pragma once
#include <iostream>

class Round {
	std::string letter;
public:
	int round;

	Round() {
		round = 0;
	}

	void next_round() {
		round = (round + 1) % 3;
	}

	char load_char() {
		std::string lett;
		std::cin >> lett;

		while (lett.length() != 1)
		{
			std::cout << std::endl << "Type a single letter and press <enter>: ";
			std::cin >> lett;
		}

		for (auto& c : lett)  
			c = toupper(c);

		return lett[0];
	}

};

