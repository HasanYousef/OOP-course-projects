#pragma once
#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() {
	// opens the text file that contains the initial maps
	m_mapsStream = ifstream("Board.txt");
	//if the file didn't open print an error message and exit
	if (!m_mapsStream.is_open()) {
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
}

//-----------------next_frame-----------------
void Controller::next_frame() {
	while (m_player.move(m_board));

	for (int enemyIndex = 0; enemyIndex < m_enemies.size(); enemyIndex++)
		m_enemies[enemyIndex].move(m_board);

}

//-----------------get_health-----------------
int Controller::get_health() const {
	return m_player.get_health();
}

//-----------------get_score-----------------
int Controller::get_score() const {
	return m_score;
}

//-----------------get_level-----------------
int Controller::get_level() const {
	return m_level;
}