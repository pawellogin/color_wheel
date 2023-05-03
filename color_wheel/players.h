#pragma once
#include <iostream>
#include <vector>

struct player{
	std::string name;
	int wallet;

	player& operator+=(int amount) {
		wallet += amount;
		return *this;
	}

	player& operator=(int amount) {
		wallet = amount;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const player& p)
	{
		std::string output;

		os << p.name << " " << p.wallet;

		return os;
	}
};

class Players {

	std::vector<player> player_list;

public:
	void add_player(std::string name) {
		player* pt = new player;
		pt->wallet = 0;
		pt->name = name;
		player_list.push_back(*pt);
	}

	void display_players(int round) {
		std::cout << "\n";
		for (int i = 0; i < 3; i++) {
			if (i == round) {
				std::cout << "\033[1;34m";
			}
			std::cout << player_list[i].name << "\t" << player_list[i].wallet << "\n";
			std::cout << "\033[0m";
		}
		std::cout << "\n";
	}

	player& get_player(int id) {
		return player_list[id];
	}
};
