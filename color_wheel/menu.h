#pragma once
#include <iostream>
#include <string>

class Menu {
	std::string options;
public:
	Menu() {
		options = "Choose: \n1. try whole password\n2. spinning the wheel";
	}

	friend std::ostream& operator<<(std::ostream& os, const Menu& menu) {
		os << menu.options;
		return os;
	}
};
