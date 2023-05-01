#include <iostream>
#include <fstream>
#include "password.h"
#include "players.h"
#include "round.h"
#include "menu.h"
#include "wheel.h"
#include <windows.h>
int main() {
	Menu menu;
	Password password;
	Wheel wheel;
	Round round;

	password.loadpassword();
	

	Players players;
	players.add_player("John");
	players.add_player("Mary");
	players.add_player("Gary");
	
	bool run = 1;
	while (run) {
		round.next_round(wheel);
		std::cout << password << "\n";
		
		password.print_is_consonant();

		players.display_players(round.round);

		std::cout << menu<<"\n";
		std::cin >> round;

		while (round.letter != "1" && round.letter != "2")
		{
			clear_screen();
			std::cout << std::endl << "Choose between [1-2]: ";
			std::cin >> round;
		}

		switch (std::stoi(round.letter)) {
		case 1: 
			std::cin >> password; std::cin >> password;
			if (password.check_password()) {
				players.get_player(round.round) += round.prizes;
				run = 0;
			}break;
		case 2:
			break;
		}
		
		clear_screen();
		
	}
	std::cout << "you win!\n";
	std::cout << players.get_player(round.round);

}

