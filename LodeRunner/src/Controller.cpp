#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() {
	open_maps_stream();
	m_level = 0;
	m_score = 0;
	m_remainingMoney = 0;
}

//-----------------run-----------------
void Controller::run() {
	m_level = 1;
	while (true) {
		m_originBoard = Board(m_mapsStream);
		m_board = Board(m_originBoard);
		run_level();
		if (m_player.get_health() == 0) {
			cout << "YOU LOST!\n";
			reset_game();
		}
		else if (m_level == NUM_OF_LEVELS) {
			cout << "YOU WON!\n";
			reset_game();
		}
		m_level++;
	}
}

//-----------------run_level-----------------
//
void Controller::run_level() {
	while (true) {
		Coord currPlayerCoord = m_player.get_coord();
		do {
			currPlayerCoord = m_player.move(m_board);
		} while (currPlayerCoord != m_player.get_coord());
		move_enemies();
	}
}

//-----------------locate_objects-----------------
//
void Controller::locate_objects() {
	int boardSize = m_originBoard.get_size();
	char currChar;
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < boardSize; col++) {
			Coord currCoord(col, row);
			currChar = m_originBoard.get_char(currCoord);
			if (currChar == PLAYER)
				m_player = Player(currCoord);
			else if (currChar == ENEMY)
				m_enemies.back(Enemy(currCoord));
			else if (currChar == MONEY)
				m_remainingMoney++;
		}
	}
}

void Controller::reset_game() {
	cout << "RESTART? (y/n) ";
	char answ;
	cin.get(answ);
	if (answ == 'y')
		exit(EXIT_SUCCESS);
	open_maps_stream();
	m_level = 0;
}

void Controller::open_maps_stream() {
	// opens the text file that contains the initial maps
	m_mapsStream = ifstream(BOARD_PATH);
	//if the file didn't open print an error message and exit
	if (!m_mapsStream.is_open()) {
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
}

void Controller::move_enemies() {
	//
}