#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

class Password {
public:
	std::string pass;
	std::vector<std::string> pass_vec;
	int mask[50];
	std::ifstream file;
	std::string pass_attempt;


public:

	Password() {
		pass = "";
		memset(mask, 0, sizeof(mask));
		pass_attempt = "";
	}

	void loadpassword() {
		srand(time(nullptr));
		file.open("data.txt");

		while (!file.eof()) {
			std::string temp;
			std::getline(file, temp);
			pass_vec.push_back(temp);
		}
		file.close();

		pass = pass_vec[rand() % pass_vec.size()];

		for (int i = 0; i < pass.size(); i++) {
			if (pass[i] == ' ') {
				mask[i] = 0;
			}
			else {
				mask[i] = 1;
			}
		}
	}

	bool is_a_vowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
			return 1;
		else
			return 0;
	}

	void print_is_consonant() {
		for (int i = 0; i < pass.size(); i++) {
			if (!is_a_vowel(pass[i]) && (mask[i]))
			{
				std::cout << " --consonants are there --";
				break;
			}
		}			
	}

	void check_password() {

	}

	friend std::ostream& operator<<(std::ostream& os, const Password& p1)
	{
		std::string output;

		for (int i = 0; i < p1.pass.size(); i++)
		{
			if (p1.mask[i] == 1) {
				output += "\033[47m";
				output += "\033[31m";
				output += ".";
			}
			else {
				output += p1.pass[i];
			}
		}
		output += "\033[0m";
		os << output;

		return os;
	}

	friend std::istream& operator>>(std::istream& is, Password& p1) {
		getline(is, p1.pass_attempt);
		return is;
	}
};

