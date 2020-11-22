#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include "Coord.h"

//the Controller class controls the game's objects' relations
class Controller {
public:
	//initializing the player score with 0 and level 1
	Controller() : m_level(0), m_score(0), m_remainingMoney(0) {}
	void run();
	//void next_frame();
private:
	void run_level();
	void locate_objects();
	int m_level,
		m_score,
		m_remainingMoney;	//storing how many money packs are remaining
	ifstream m_mapsStream;	//the maps file stream
	Board m_originBoard = Board(),
		m_board = Board();
	Player m_player = Player();
	vector <Enemy> m_enemies = {};	//storing the enemies as a vector
};