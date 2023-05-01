#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Wheel {
public:
	std::vector<int> prizes;

	Wheel() {
		prizes = { -1, 0, 100, 200, 100,
		200, 100, 200, 500, 500, 1000,
		1000, 1500, 2000, 3000, 5000 };
	}

	void operator=(const Wheel& other) {
		// Copy the vector of prizes
		this->prizes = other.prizes;
	}

	operator int() const {
		// Randomly select a prize from the vector
		std::srand(std::time(nullptr)); // Seed the random number generator
		int index = std::rand() % this->prizes.size();
		return this->prizes[index];
	}
	
};
