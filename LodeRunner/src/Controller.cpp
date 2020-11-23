#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() {
	// opens the text file that contains the initial maps
	m_mapsStream = ifstream(BOARD_PATH);
	//if the file didn't open print an error message and exit
	if (!m_mapsStream.is_open()) {
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
	m_level = 0;
	m_score = 0;
	m_remainingMoney = 0;
}

//-----------------run-----------------
void Controller::run() {
	while (m_level <= NUM_OF_LEVELS) {
		m_originBoard = Board(m_mapsStream);
		m_board = Board(m_originBoard);
		m_level++;
		run_level();
		if (m_player.get_health() == 0) {
			lost_menu();
		}
	}
	won_menu();
}

//-----------------run_level-----------------
//
void Controller::run_level() {
	locate_objects();
	while (true) {
		//m_player
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

void Controller::lost_menu() {

}

void Controller::won_menu() {

}