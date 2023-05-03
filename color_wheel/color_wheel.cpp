#include <iostream>
#include <fstream>
#include "password.h"
#include "players.h"
#include "round.h"
#include "menu.h"
#include "wheel.h"
#include <chrono>
#include <thread>

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
			}
			else {
				std::cout << "\nwrong!";
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			break;
		case 2: 
			if (round.prizes == 0) {
				std::cout << "lost queue\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			if (round.prizes == -1) {
				std::cout << "bankrupt\n"; 
				players.get_player(round.round)= 0;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			else {
				std::cout << round.prizes << "\n\n";
				std::cout << players.get_player(round.round).name;
				std::cout << " :enter a letter\n";
				std::cin >> round;
				for (int i = 0; i < password.pass.size(); i++) {
					if ((password.pass[i] == round.letter[0]) && password.mask[i] == 1) {
						password.mask[i] = 0;
						players.get_player(round.round) += round.prizes;
						round.skip_round = 1;
					}
				}
			}
			break;
		}
		clear_screen();
		for (int i = 0; i < password.pass.size(); i++) {
			if (password.mask[i] == 1) {
				run = 1;  break; }
			else run = 0;
		}

	}
	std::cout << "you win! ";
	std::cout << players.get_player(round.round);

}

