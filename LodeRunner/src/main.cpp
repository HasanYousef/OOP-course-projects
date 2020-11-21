#pragma once
#include <iostream>
using namespace std;

#include "Macros.h"
#include "Controller.h"

int main()
{
	bool cont;
	do {
		Controller game;
		while (game.get_health() > 0 && game.get_level() <= NUM_OF_LEVELS) {
			game.next_frame();
			cout << BOTTOM_LINE << endl;
			cout << "SCORE: " << game.get_score()
				<< " LEVEL: " << game.get_level()
				<< " HEALTH: " << game.get_health();
		}
		if (game.get_health() == 0) {
			cout << "GAME OVER! you lost :(" << endl
				<< "Try again? (y/n) ";
		}
		else {
			cout << "WELL DONE! you finished the game, here is a cookie." << endl
				<< "Restart? (y/n) ";
		}
		cont = (getchar() == 'y');
	} while (cont);

	return EXIT_SUCCESS;
}
