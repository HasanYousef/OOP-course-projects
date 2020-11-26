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
		locate_objects();
		run_level();
		if (m_player.get_health() == 0) {
			cout << "YOU LOST!\n";
			reset_game();
		}
		else if (m_level == NUM_OF_LEVELS) {
			cout << "YOU WON!\n";
			reset_game();
		}
		m_score += 50 * m_level;
		m_level++;
	}
}

//-----------------run_level-----------------
//
void Controller::run_level() {
	while (true) {
		m_board.print();
		print_ui();
		Coord oldPlayerCoord = m_player.get_coord(),
			currPlayerCoord = m_player.move(m_board);
		while (oldPlayerCoord == currPlayerCoord) {
			oldPlayerCoord = m_player.get_coord();
			currPlayerCoord = m_player.move(m_board);
		}
		//we move the charachters
		move_player(oldPlayerCoord);
		move_enemies();
		//if the enemy hit the player
		if (get_hit()) {
			m_player.die();
			m_originBoard.print(); //we back from start
			if (m_player.get_health() == 0) {
				return;
			}
		}
		//if the player get a coin
		if (getcoin()) {
			m_score += (m_level * 2);
			m_remainingMoney--;
			if (m_remainingMoney == 0) {//if we get all coins
				return;
			}
		}
		system("cls");
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
				m_enemies.push_back(Enemy(currCoord));
			else if (currChar == MONEY)
				m_remainingMoney++;
		}
	}
}

//---------------------------------------------
void Controller::reset_game() {
	cout << "RESTART? (y/n) ";
	char answ;
	cin.get(answ);
	if (answ == 'n')
		exit(EXIT_SUCCESS);
	open_maps_stream();
	m_level = 0;
}

//---------------------------------------------
void Controller::open_maps_stream() {
	// opens the text file that contains the initial maps
	m_mapsStream = ifstream(BOARD_PATH);
	//if the file didn't open print an error message and exit
	if (!m_mapsStream.is_open()) {
		cerr << "Cannot open the map file\n";
		exit(EXIT_FAILURE);
	}
}

//----------------------------------------------------------------
void Controller::move_player(const struct Coord oldPlayerCoord)
{
	if (m_board.get_char(m_player.get_coord()) == LADDER) {
		m_board.set_char(m_player.get_coord(), PLAYER_ON_LADDER);
        //we check if the player taked a coin
		if (m_originBoard.get_char(oldPlayerCoord) == MONEY) {
			m_board.set_char(oldPlayerCoord, EMPTY);
			return;
		}//if the old elment not a coin
		m_board.set_char(oldPlayerCoord, m_originBoard.get_char(oldPlayerCoord));
		return;
	}//if its on a ROPE or on a Ground
	if (m_originBoard.get_char(oldPlayerCoord) == PLAYER) {
		m_board.set_char(m_player.get_coord(), PLAYER);
		m_board.set_char(oldPlayerCoord, EMPTY);
		if (m_originBoard.get_char(oldPlayerCoord) == MONEY) {
			m_board.set_char(oldPlayerCoord, EMPTY);
			return;
		}//if the old elment not a coin
		return;
	}
	m_board.set_char(m_player.get_coord(), PLAYER);
	m_board.set_char(oldPlayerCoord, m_originBoard.get_char(oldPlayerCoord));
	if (m_originBoard.get_char(oldPlayerCoord) == MONEY) {
		m_board.set_char(oldPlayerCoord, EMPTY);
		return;
	}//if the old elment not a coin
}

//---------------------------------------------
void Controller::move_enemies()
{
	Coord old_place;
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		old_place = m_enemies[enemy].get_coord();
		char oldChar = m_originBoard.get_char(old_place);
		Coord newCoord =  m_enemies[enemy].move(m_board);
		m_board.set_char(newCoord, ENEMY);
		if (oldChar == ENEMY)
			oldChar = EMPTY;
		m_board.set_char(old_place, oldChar);
	}
}

//---------------------------------------------
//bool func return true if the player on the
//same element of the enemy return false if not
bool Controller::get_hit() 
{
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		if (m_player.get_coord() == m_enemies[enemy].get_coord()) {
			return true;
		}
	}
	return false;
}

//---------------------------------------------
//bool func return true if the player on the
//same element of the coin return false if not
bool Controller::getcoin()
{
	return (m_originBoard.get_char(m_player.get_coord()) == MONEY);
}

void Controller::print_ui() {
	cout << BOTTOM_LINE << endl
		<< "remaining money: " << m_remainingMoney << "    ";
}