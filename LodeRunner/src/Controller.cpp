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
			system("cls");
			cout << "YOU LOST!\n";
			exit(EXIT_SUCCESS);
		}
		else if (m_level == NUM_OF_LEVELS) {
			system("cls");
			cout << "YOU WON!\n";
			exit(EXIT_SUCCESS);
		}
		m_score += 50 * m_level;
		m_level++;
		m_enemies.clear();
	}
}

//-----------------run_level-----------------
//here we run the current level we on it we
//print the board after that we read player
//movement until we get new coord after that 
//we check if the player get a money after
//that we call the player move func that its 
//put the player on the new elment same thing
//for the move_enemies after that we check if
//the player get hit from the enemy 
void Controller::run_level() {
	bool origprint = false;
	while (true) {
		if (!origprint) {
			system("cls");
			set_gold_on_map();
			m_board.print();
		}
		origprint = false;
		print_ui();
		Coord oldPlayerCoord = m_player.get_coord(),
			currPlayerCoord = m_player.move(m_board);
		while (oldPlayerCoord == currPlayerCoord) {
			oldPlayerCoord = m_player.get_coord();
			currPlayerCoord = m_player.move(m_board);
		}
		//if the player get a coin
		if (getcoin()) {
			m_score += (m_level * 2);
			get_money();
			if (m_remainingMoney == 0) {//if we get all coins
				return;
			}
		}
		//we move the charachters
		move_player(oldPlayerCoord);
		move_enemies();
		//if the enemy hit the player
		if (get_hit()) {
			m_player.die();
			if (m_player.get_health() == 0) {
				break;
			}
			origprint = true;
		}
		system("cls");
		if (origprint) {
			m_originBoard.print();
			m_money_packs.clear();
			m_enemies.clear();
			int currHealth = m_player.get_health();
			m_board = Board(m_originBoard);
			locate_objects();
			m_player.set_health(currHealth);
		}
	}
}

//-----------------locate_objects-----------------
//this func move on the board (array) and locate
//the object we have for example if the elment x.y
//have a enemy we add to the vector of enemy a enemy
//if we find a coin we add to the integer of 
//m_remainingMoney 1 this is how its work
void Controller::locate_objects() {
	m_remainingMoney = 0;
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
			else if (currChar == MONEY) {
				m_money_packs.push_back(Money(Coord(col, row)));
				m_remainingMoney++;
			}
		}
	}
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
//this func take the old coord of the player and in this func we 
//want to move the player to the new elment the indexes of the new
//element are saved on the player private coord we do here that
//we set the player on the new elment that we have and check if
//the player on ladder we print it S if no we print it @ and we
//check the old element if its was a coin or a player or a enemy
//we print empty else we print the char from origin board
void Controller::move_player(const struct Coord oldPlayerCoord)
{
	if (m_originBoard.get_char(m_player.get_coord()) == LADDER) {
		m_board.set_char(m_player.get_coord(), PLAYER_ON_LADDER);
        //we check if the player taked a coin
		if (m_originBoard.get_char(oldPlayerCoord) == MONEY) {
			m_board.set_char(oldPlayerCoord, EMPTY);
			return;
		}//if the old elment not a coin
		m_board.set_char(oldPlayerCoord, m_originBoard.get_char(oldPlayerCoord));
		if (m_originBoard.get_char(oldPlayerCoord) == PLAYER) {
			m_board.set_char(oldPlayerCoord, EMPTY);
		}
		return;
	}//if its on a ROPE or on a Ground
	if (m_originBoard.get_char(oldPlayerCoord) == PLAYER ||
		m_originBoard.get_char(oldPlayerCoord) == ENEMY) {
		m_board.set_char(m_player.get_coord(), PLAYER);
		m_board.set_char(oldPlayerCoord, EMPTY);
		if (m_board.get_char(oldPlayerCoord) == MONEY) {
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
//this void func let the enemies move we move
//on every elment on the vector of enemies on
//every elment we call the move func of the 
//enemy that we build it on the enemy class
//its return the coord that we have to move 
//on it and we move the enemy to the coord
//and give the old enemy the char its have 
//to by the origin board
void Controller::move_enemies()
{
	Coord old_place;
	//to move on all the enemies
	for (int enemy = 0; enemy < m_enemies.size(); enemy++) {
		old_place = m_enemies[enemy].get_coord();//save old coord
		char oldChar = m_originBoard.get_char(old_place);//get char of old coord
		Coord newCoord =  m_enemies[enemy].move(m_originBoard, m_player.get_coord());
		if (oldChar == ENEMY || oldChar == PLAYER || oldChar == MONEY)
			oldChar = EMPTY;
		m_board.set_char(old_place, oldChar);//set the origin char
		m_board.set_char(m_board.get_ground(newCoord), ENEMY);//set the enemy 
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
	return (m_board.get_char(m_player.get_coord()) == MONEY);
}

//-----------------------------------------------
//this func print a line under the map and under 
//the line we print how mony we have, the helth
//of the player and the current level
void Controller::print_ui() {
	cout << BOTTOM_LINE << endl
		<< "Score: " << m_score << "\n"
		<< "Health: " << m_player.get_health() << "\n"
		<< "Level: " << m_level << endl;
}

void Controller::get_money() {
	for (int index = 0; index < m_money_packs.size(); index++) {
		if (m_money_packs[index].m_coord == m_player.get_coord()) {
			m_money_packs[index].m_isTaken = true;
			m_remainingMoney--;
			return;
		}
	}
}

void Controller::set_gold_on_map() {
	for (int index = 0; index < m_money_packs.size(); index++) {
		Coord moneyCoord = m_money_packs[index].m_coord;
		if (m_money_packs[index].m_isTaken
			&& (m_board.get_char(moneyCoord) == MONEY)) {
			m_board.set_char(moneyCoord, EMPTY);
		}
		if (!m_money_packs[index].m_isTaken
			&& (m_board.get_char(moneyCoord) == EMPTY)) {
			m_board.set_char(moneyCoord, MONEY);
		}
	}
}