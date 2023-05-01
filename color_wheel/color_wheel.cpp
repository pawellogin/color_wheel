#include <iostream>
#include <fstream>
#include "password.h"
#include "players.h"
#include "round.h"

int main() {

	Password p1;
	p1.loadpassword();
	std::cout << p1<<"\n";

	Players players;
	players.add_player("John");
	players.add_player("Mary");
	players.add_player("Gary");

	p1.print_is_consonant();
	
	Round r1;

	players.display_players(r1.round);



}