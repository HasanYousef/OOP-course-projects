#pragma once

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include "Coord.h"
#include "Macros.h"

//the Controller class controls the game's objects' relations
class Controller {
public:
	//initializing the player score with 0 and level 1
	Controller();
	void run();
	//void next_frame();
private:
	void run_level();
	void locate_objects();
	void reset_game();
	void open_maps_stream();
	void move_enemies();
	int m_level,
		m_score,
		m_remainingMoney;	//storing how many money packs are remaining
	ifstream m_mapsStream;	//the maps file stream
	Board m_originBoard = Board(),
		m_board = Board();
	Player m_player;
	vector <Enemy> m_enemies = {};	//storing the enemies as a vector
};