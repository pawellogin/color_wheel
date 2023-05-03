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
		this->prizes = other.prizes;
	}

	operator int() const {
		std::srand(std::time(nullptr)); 
		int index = std::rand() % this->prizes.size();
		return this->prizes[index];
	}
	
};
